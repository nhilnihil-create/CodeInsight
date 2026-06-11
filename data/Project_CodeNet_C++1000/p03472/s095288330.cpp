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
    vector<int> b(n);
    int a_max = 0;
    rep(i,n){
        int x,y; cin >> x >> b.at(i);
        chmax(a_max,x);
    }
    sort(all(b));
    reverse(all(b));
    ll cnt = 0;

    while(cnt < n && b.at(cnt) >= a_max){
        h -= b.at(cnt);
        cnt++;
        if(h <= 0) break;
    }
    while(h > 0){
        h -= a_max;
        cnt++;
    }
    cout << cnt << endl;
    return 0;
}
