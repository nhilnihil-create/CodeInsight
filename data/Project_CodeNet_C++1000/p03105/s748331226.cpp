#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i,n) for (int i = 0; i < (n); ++i)
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
const ll INF=1LL<<60;
const int inf=1<<30;
const int mod=1e9+7;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int a,b,c;cin >> a >> b >> c;
    cout << min(c,b/a) << endl;
}