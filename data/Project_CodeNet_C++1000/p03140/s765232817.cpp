#include <bits/stdc++.h>
using namespace std;

template<typename T>
void out(T x) { cout << x << endl; exit(0); }
#define watch(x) cout << (#x) << " is " << (x) << endl





using ll = long long;

const ll mod = 1e9+7;
const int maxn = 1e6 + 5;





int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);  cout.tie(0);

    int n;
    string a,b,c;
    cin>>n>>a>>b>>c;
    int res = 0;
    for (int i=0; i<n; i++) {
	int cur=3;
	cur = min(cur, (a[i]!=b[i])+(a[i]!=c[i]));
	cur = min(cur, (b[i]!=a[i])+(b[i]!=c[i]));
	cur = min(cur, (c[i]!=a[i])+(c[i]!=b[i]));
	res += cur;
    }
    cout<<res<<endl;
    
    
    return 0;
}
