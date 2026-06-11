#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
#define all(x) (x).begin(),(x).end()
#define cyes cout<<"YES"<<endl
#define cno cout<<"NO"<<endl
#define sp <<" "<<
#define cst(x) cout<<fixed<<setprecision(x)
#define pi 3.14159265359
#define mod 1000000007
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

    int h,w,d; cin >> h >> w >> d;
    map<int,pint> mp;
    rep(i,h)rep(j,w){
        int key; cin >> key;
        mp[key] = make_pair(i,j);
    }
    vector<ll> cum(h*w+1);
    for(int i = 1; i <= d; i++) cum.at(i) = 0;
    for(int i = d+1; i <= h*w; i++){
        pint n = mp.at(i);
        pint nv = mp.at(i-d);
        cum.at(i) = cum.at(i-d) + abs(n.first-nv.first) + abs(n.second - nv.second);
    }
    int q; cin >> q;
    rep(i,q){
        int l,r; cin >> l >> r;
        ll cost;
        cost = cum.at(r) - cum.at(l);
        cout << cost << endl;
    }

    return 0;   

}
