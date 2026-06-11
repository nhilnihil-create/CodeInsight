//c++ テンプレ
#include<bits/stdc++.h>
using namespace std;

typedef long long llint;
typedef long double ld;
typedef pair<int,int> P;

#define inf 1e9
#define mod 1000000007
#define sort(v) sort(v.begin(),v.end())
#define reverse(v) reverse(v.begin(),v.end())

priority_queue<llint,vector<llint>,greater<llint> > que;
priority_queue<llint> Que;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }

void solve(){
    double t,x;
    cin >> t >> x;
    double ans=t/x;
    printf("%.10f\n",ans);
    
}

int main(){
    solve();
    return 0;
}


