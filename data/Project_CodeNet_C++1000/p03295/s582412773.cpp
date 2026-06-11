#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define rep1(i,n) for(int i=1;i<=(int)n;i++)
#define sp(n) cout << fixed << setprecision(n)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
typedef long long ll;
using namespace std;
const int MAX_N=1e+6;
int bit[MAX_N+1], n;
int sum(int i){
    int s=0;
    while(i>0){
        s+=bit[i];
        i-=i&-i;
    }
    return s;
}
void add(int i,int x){
    while(i<=n){
        bit[i]+=x;
        i+=i&-i;
    }
}

int main(void){
    ll m;cin>>n>>m;
    vector<pair<int,int>> p(m);
    rep(i,m){
        cin>>p[i].second>>p[i].first;
        p[i].first--;p[i].second--;
    }
    sort(p.begin(),p.end());
    int res=0;
    rep(i,m){
        int a=p[i].second,b=p[i].first;
        ll sa=sum(a),sb=sum(b);
        if(sa==sb){
            add(b,1);
            res++;
        }
    }
    cout<<res<<endl;
}