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

    int n,m; cin >> n >> m;
    vector<vector<pint>> data(n);
    rep(i,m){
        int p,y; cin >> p >> y;
        data.at(p-1).push_back(make_pair(y,i));
    }
    map<int,string> mp;
    rep(i,n){
        sort(all(data.at(i)));
        rep(j,data.at(i).size()){
            string ans = "";
            string ken = to_string(i+1);
            rep(i,6-ken.size()) ans += '0';
            ans += ken;
            string ban = to_string(j+1);
            rep(i,6-ban.size()) ans += '0';
            ans += ban;
            mp[data.at(i).at(j).second] = ans;
        }
    }
    rep(i,m) cout << mp.at(i) << endl;
    return 0;
}
