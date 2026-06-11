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

    vector<int> v(4);
    for (int i=0; i<4; i++) {
	cin>>v[i];
    }
    vector<int> w={1,9,7,4};

    sort(v.begin(), v.end());
    sort(w.begin(), w.end());

    cout<<(v==w ? "YES\n" : "NO\n");
    
    
    return 0;
}
