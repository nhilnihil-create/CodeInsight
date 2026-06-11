#include <bits/stdc++.h>
using namespace std; typedef long double ld; typedef long long ll;
typedef unsigned long long ull;
#define MP make_pair
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORR(x,arr) for(auto& x:arr)
#define VI vector<int>
#define PII pair<int, int>
#define FI first 
#define SE second
#define ALL(x) (x).begin(), (x).end()
const int INF=1<<30; const ll LINF=1LL<<60 ; const ll MOD=1e9+7 ;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a = b; return 1; } return 0; }
//-------------------

string s;
int w;
int main(){
    cin >> s >> w;
    FOR(i,0,(s.size()-1)/w){
        cout << s[w*i];
    }
    return 0;
}