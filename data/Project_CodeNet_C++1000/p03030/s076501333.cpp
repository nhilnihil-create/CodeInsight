#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define INF 100000000
#define rep(i,s,n) for (int i = (int)(s); i < (int)(n); i++)
#define mp make_pair
ll mod = 1000000007;
ll mod2 = 998244353;

int main(){
	int n;cin>>n;
    vector<string> a(n);
    map<string,vector<int>> b;
    map<pair<string,int>,int> d;
    vector<pair<string,int>> c;
    rep(i,0,n){
        string s;cin>>s;
        int p;cin>>p;
        a[i] = s;
        b[s].push_back(p);
        d[mp(s,p)] = i+1;
    }
    sort(a.begin(),a.end());
    int j = 1;
    rep(i,0,n){
        sort(b[a[i]].rbegin(),b[a[i]].rend());
        for(auto x : b[a[i]]){
            cout<<d[mp(a[i],x)]<<endl;
        }
        b.erase(a[i]);
    }
}