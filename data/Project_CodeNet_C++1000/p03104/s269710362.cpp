#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
#define all(x) (x).begin(),(x).end()
#define cyes cout<<"Yes"<<endl
#define cno cout<<"No"<<endl
#define sp <<" "<<
#define cst(x) cout<<fixed<<setprecision(x)
#define pi 3.14159265358979
#define mod 1000000007
using namespace std;
using ll = long long;
using ld = long double;
using vi = vector<int>;
using vl = vector<ll>;
using Graphi = vector<vi>;
using que_a = priority_queue<int, vector<int>, greater<int> >;
using que_d = priority_queue<int>;
using pint = pair<int,int>;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
struct edge {
    int to; 
    int weight;
    edge(int t, int w) : to(t),weight(w) {}
};

ll calc(ll a){
    ++a;
    ll ans = 0;
    rep(i,40){
        ll cnt = 0;
        ll loop = (1LL << (i+1));
        cnt = a/loop * loop/2;
        cnt += max(a%loop - loop/2,0LL);
        if(cnt%2 == 1){
            ans += loop/2;
        }
    }
    return ans;
}


int main(){

    ll a,b; cin >> a >> b;
    ll ans = calc(b)^calc(a-1);
    cout << ans << endl;
    return 0;

}