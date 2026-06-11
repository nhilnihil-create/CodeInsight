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

    ll k,a,b;

    cin>>k>>a>>b;
    if (b<=a+2) {
	out(1+k); // only hit
    }


    ll cur = 1;
    ll need = a-1;
    if (need >= k) {
	cur += k;
	out(cur);
    }

    cur += need;
    k -= need;

    cur += (k/2)*(b-a);
    cur += (k%2);
    cout<<cur<<endl;
    
    return 0;
}
