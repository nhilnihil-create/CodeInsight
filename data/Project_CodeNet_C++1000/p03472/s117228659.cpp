#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
#define all(x) (x).begin(),(x).end()
#define cyes cout<<"YES"<<endl
#define cno cout<<"NO"<<endl
#define sp <<" "<<
#define cst(x) cout<<fixed<<setprecision(x)
#define pi 3.14159265359
#define mod 1000000007
struct edge {
    int to; 
    int weight;
    edge(int t, int w) : to(t),weight(w) {}
};
using namespace std;
using ll = long long;
using ld = long double;
using Graph = vector<vector<int>>;
using que_a = priority_queue<int, vector<int>, greater<int> >;
using que_d = priority_queue<int>;
using pint = pair<int,int>;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

int main(){

    int n,h; cin >> n >> h;
    vector<int> a(n),b(n);
    rep(i,n) cin >> a.at(i) >> b.at(i);
    sort(all(a));sort(all(b));
    reverse(all(a));reverse(all(b));
    ll cnt = 0;
    int i = 0;

    while(i < n && b.at(i) >= a.at(0)){
        h -= b.at(i);
        cnt++;
        i++;
        if(h <= 0) break;
    }
    while(h > 0){
        h -= a.at(0);
        cnt++;
    }
    cout << cnt << endl;
    return 0;
}
