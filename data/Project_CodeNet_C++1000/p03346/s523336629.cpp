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

    int n; cin >> n;
    vector<int> so(n);
    rep(i,n){
        int a; cin >> a;
        a--;
        so.at(a) = i;
    }
    int cnt = 1;
    int ans = 0;
    if(n == 1){
        cout << 0 << endl;
        return 0;
    }
    rep(i,n-1){
        if(so.at(i) < so.at(i+1)){
            cnt++;
        }
        else{
            chmax(ans,cnt);
            cnt = 1;
        }
    }
    chmax(ans,cnt);
    cout << n-ans << endl;
    return 0;
}
