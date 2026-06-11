#include <bits/stdc++.h>
#define be(v) (v).begin(),(v).end()
#define pb(q) push_back(q)
typedef long long ll;
using namespace std;
const ll mod=1000000007, INF=(1LL<<60);
#define doublecout(a) cout<<fixed<<setprecision(10)<<a<<endl;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    string s;
    cin >> s;
    int n = s.length();
    bool ok = false;
    string t = "keyence";
    for(int i=0;i<=7;i++){
    	if(s.substr(0, (7 - i)) + s.substr(n - i, i) == t) ok = true;
    }
    if(ok) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}
