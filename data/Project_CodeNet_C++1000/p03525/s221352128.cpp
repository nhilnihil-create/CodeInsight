#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;cin>>n;
    map<int,int>a;
    for(int i=0;i<n;++i){
        int x;cin>>x;
        a[x]++;
    }
    if(a[0]>0)cout<<0<<endl;
    else{
        vector<int>b,c(24,0);
        c[0]=1;
        if(a[12]>0)c[12]=1;
        for(int i=1;i<=12;++i){
            if(a[i]>2){
                cout<<0<<endl;
                return 0;
            }
            else if(a[i]==2){
                c[i]=1;
                c[24-i]=1;
            }
            else if(a[i]==1&&i!=12)b.push_back(i);
        }
        int ans=0;
        for(int i=0;i<(1<<b.size());++i){
            for(int j=0;j<b.size();++j){
                if((i>>j)&1){
                    c[24-b[j]]=1;
                }
                else c[b[j]]=1;
            }
            int cnt1=0,cnt2=100;
            for(int j=1;j<=23;++j){
                if(c[j]==0)cnt1++;
                else{
                    if(cnt2>cnt1)cnt2=cnt1;
                    cnt1=0;
                }
            }
            if(cnt1>0&&cnt2>cnt1)cnt2=cnt1;
            if(cnt2+1>ans)ans=cnt2+1;
            for(int j=0;j<b.size();++j){
                c[b[j]]=0;
                c[24-b[j]]=0;
            }
        }
        cout<<ans<<endl;
    }
}