#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vpii = vector<pair<int,int>>;
using vpll = vector<pair<ll,ll>>;
using vi = vector<int>;
#define rep(i,n) for(int i=0;i<(int) n;i++)
#define rep1(i,m,n) for(int i=(int) m;i<(int) n;i++)
#define fix(n) cout << fixed << setprecision((int)n)

void absll(ll &x) {
    if(x>=0) return ;
    else x=-x; return;
}

template<class T> inline bool chmax(T &a, T b) {
    if(a<b) {
        a=b; return 1;
    } 
    return 0;
}

template<class T> inline bool chmin(T &a, T b) {
    if(a>b) {
        a=b; return 1;
    } 
    return 0;
}

const ll INF = 1LL << 60;

int N;

//DPテーブル
vector<ll> dp(100010);

int main() {
    int a,b,sum=0;
    cin >> a >> b;
    rep1(i,1,b-a) sum+=i;
    cout << sum-a << endl; 
}