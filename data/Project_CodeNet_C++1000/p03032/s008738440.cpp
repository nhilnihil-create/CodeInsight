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
    auto iv=v;
    reverse(iv.begin(),iv.end());
    ll res=0;
    
    for(int l=0;l<=min(k,n);l++){
        int buf=min(n,k)-l;
        for(int r=0;r<=buf;r++){
            ll tmp=0;
            rep(i,l) tmp+=v[i];
            rep(j,r) tmp+=iv[j];
            priority_queue<ll, vector<ll>, greater<ll> > que;
            rep(i,l)que.push(v[i]);
            rep(i,r)que.push(iv[i]);
            rep(i,k-(r+l)){
                if(que.size()==0||que.top()>0)break;
                tmp-=que.top();que.pop();
            }
            chmax(res,tmp);
        }
    }
    cout<<res<<endl;
}