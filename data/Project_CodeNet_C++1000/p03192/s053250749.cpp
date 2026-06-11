#include "bits/stdc++.h"
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size)
#define MOD 1000000007
const long long mod = 1e9+7;
typedef vector<long long> Vl;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<Vl> VVl;
typedef pair<int, int> PII;
typedef long long ll;

int main(){
    int a=0,b=0,c=0,d,n=1,x=0,y;
    VI m(5);
    string s,s1,s2;
    cin >> s;
    rep(i,4) if (s[i] == '2') c++;

    cout << c << endl;
    return 0;
} 