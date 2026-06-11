#include <bits/stdc++.h>
using namespace std;
#define rep(i,n)for(int i=0;i<(n);i++)
#define ALL(a) (a).begin(), (a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define pb push_back
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

int main(){
    int n, t; cin >> n >> t;
    vector<P> vec;
    rep(i,n){
        int c, t; cin >> c >> t;
        vec.push_back(P(c,t));
    }
    sort(ALL(vec));
    for(auto p : vec){
        if(p.second <= t){
            cout << p.first << endl;
            return 0;
        }
    }
    cout << "TLE" << endl;
}