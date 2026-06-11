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

    vector<int> f(4);
    for (int i=0; i<3; i++) {
	int u,v;cin>>u>>v;
	--u; --v;
	f[u]++;
	f[v]++;
    }

    int hi=*max_element(f.begin(), f.end());
    cout<<(hi>2?"NO\n":"YES\n");
    
    
    return 0;
}
