#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll = long long;
using vi = vector<int>;
using vv = vector<vi>;
using P  = pair<int,int>;
//const int INF = 1001001001;
const int MOD = 1000003;

int main(){
    string s;
    cin >> s;
    int ans = 0;
    rep(i,4)if(s[i]=='+')ans++;else ans--;
	cout << ans << endl;
    return 0;
}