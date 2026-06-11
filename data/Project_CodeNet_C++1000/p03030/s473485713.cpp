#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
const int INF = 1001001001;
const int mod = 1000000007;
using P = pair<string,int>;

int main(){
    int n;
    cin >> n;
    vector<P> sp;
    map<P,int> m;
    rep(i,n){
        string s;int p;
        cin >> s >> p;
        p = -p;
        sp.emplace_back(s,p);
        P mp(s,p);
        m[mp] = i+1;
    }
    sort(sp.begin(),sp.end());
    for(auto p : sp){
        cout << m.at(p) << endl;
    }
}