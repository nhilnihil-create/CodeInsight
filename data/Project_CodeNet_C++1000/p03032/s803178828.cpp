#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


int main(){
    int n,kk;
    cin>>n>>kk;
    vector<ll> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    ll ans=0;
    for(int i=-1;i<n;i++){
        for(int j=n;j>=0&&i<j;j--){
            if(i+1+n-j>kk) continue;
            ll sum=0;
            //ll dec=0;
            priority_queue<ll,vector<ll>,greater<ll>> que;
            for(int k=0;k<=i;k++){
                que.push(a[k]);
                sum+=a[k];
            }
            for(int k=j;k<n;k++){
                que.push(a[k]);
                sum+=a[k];
            }
            for(int k=0;k<kk-(i+1+n-j)&&que.size();k++){
                ll p=que.top();
                que.pop();
                if(p>=0) break;
                sum-=p;
            }
            ans=max(ans,sum);
        }
    }
    cout<<ans<<endl;
}