#include <bits/stdc++.h>
#define be(v) (v).begin(),(v).end()
#define pb(q) push_back(q)
typedef long long ll;
using namespace std;
const ll mod=1000000007, INF=mod*mod*3LL;
#define doublecout(a) cout<<fixed<<setprecision(10)<<a<<endl;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    string s;
    int a = 0, b = 0;
    cin >> s;
    int n = s.length();
    for(int i=0;i<n;i++){
    	if(s[i] == '1') a++;
    	else b++;
    }
    a = min(a, b);
    cout << a * 2 << endl;
    return 0;
}
