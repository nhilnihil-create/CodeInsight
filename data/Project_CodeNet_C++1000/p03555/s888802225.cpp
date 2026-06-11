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
    string s, t;
    cin >> s >> t;
    if(s[0] == t[2] && s[1] == t[1] && s[2] == t[0]){
    	cout << "YES" << endl;
    }else{
    	cout << "NO" << endl;
    }
    return 0;
}
