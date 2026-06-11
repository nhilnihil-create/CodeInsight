#include<bits/stdc++.h>
using namespace std;
//define int int64_t
#define ll long long
map<int,int>M;
int pref[2*100*1000+4][22]={0};
int last_time[2*100*1000+3][22]={0};
signed main(){
    int n;cin>>n;
    ll ans=0;
    memset(pref,0,sizeof(pref));
    memset(last_time,0,sizeof(last_time));

    //for(int j=0;j<=20;++j)first_time[j]=n+1;
    for(int i=1;i<=n;++i){
        int va;cin>>va;
        int cnt=0;
        for(int j=0;j<20;++j){
            pref[i][j]=pref[i-1][j];
            if(((va>>j)&1)==1)pref[i][j]+=1;            
            if(last_time[pref[i][j]][j]==0)
              last_time[pref[i][j]][j]=i;
        }
        int first_valid_indx=1;
        for(int j=0;j<20;++j){
            //cout<<pref[i][]
            if(pref[i][j]<=1)continue;
            else{
  //              cout<<i<<" "<<j<<" "<<pref[i][j]<<endl;
    //            cout<<last_time[pref[i][j]-1][j]<<" ls"<<endl;
                first_valid_indx=max(first_valid_indx,1+last_time[pref[i][j]-1][j]);
            }
        }
//        cout<<i<<" "<<first_valid_indx<<" i,first_valid_indx\n";
        ans+=1LL*(i-(first_valid_indx)+1);
    }
    cout<<ans<<"\n";
    return 0;
}
