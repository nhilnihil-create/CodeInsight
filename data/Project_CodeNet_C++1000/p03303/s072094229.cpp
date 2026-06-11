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

    string s;
    int x;
    cin>>s>>x;
    int n =s.length();
    for (int i=0; i<n; i+=x) {
	cout<<s[i];
    }
    cout<<endl;
    
    return 0;
}
