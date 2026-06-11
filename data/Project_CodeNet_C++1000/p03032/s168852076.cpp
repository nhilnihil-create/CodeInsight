#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define rep1(i,n) for(int i=1;i<=(int)n;i++)
#define sp(n) cout << fixed << setprecision(n)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
typedef long long ll;
using namespace std;
int main(void){
    int n,k;cin>>n>>k;
    vector<ll> v(n);
    rep(i,n) cin>>v[i];
    vector<ll> a(n+1,0),inva(n+1,0);
    rep(i,n)a[i+1]=a[i]+v[i];
    auto iv=v;
    reverse(iv.begin(),iv.end());
    rep(i,n)inva[i+1]=inva[i]+iv[i];
    ll res=0;
    for(int i=0;i<=k;i++){
        for(int j=0;j<=min(i,n);j++){//取り出す作業を何回行うか
            for(int l=0;l<=j;l++){//左から何回取り出すか
                ll tmp=0;
                tmp+=a[l];
                int r=j-l;
                tmp+=inva[r];
                int buf=i-j;
                priority_queue<ll, vector<ll>, greater<ll> > que;
                rep(x,l)que.push(v[x]);
                rep(x,r)que.push(iv[x]);
                rep(x,buf){
                    if(que.size()==0)break;
                    tmp-=que.top();que.pop();
                }
                chmax(res,tmp);
            }
        }
    }
    cout<<res<<endl;
}
