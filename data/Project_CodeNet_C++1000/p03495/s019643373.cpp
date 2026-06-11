#include<bits/stdc++.h>
using namespace std;
using ll=long long int;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int n,k;
    cin>>n>>k;
    vector<int>a(n);
    rep(i,n)cin>>a[i];
    int cnt=0;
    int ans=0;
    vector<int>counter(n,0);
    rep(i,n){
        counter[a[i]-1]+=1;
    }
    int c=0;
    rep(i,counter.size()){
        if(counter[i]!=0)c+=1;
    }
    sort(counter.begin(),counter.end());
   
    if(k>=c)cout<<0<<endl;
    else{
        rep(i,counter.size()){
            if(cnt==c-k)break;
            else if(counter[i]!=0){
                ans+=counter[i];
                cnt+=1;
            }
        }
        cout<<ans<<endl;
    }
         
}