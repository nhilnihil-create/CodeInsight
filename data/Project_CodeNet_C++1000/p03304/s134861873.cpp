#include <bits/stdc++.h>
using namespace std;

template<typename T>
void out(T x) { cout << x << endl; exit(0); }
#define watch(x) cout << (#x) << " is " << (x) << endl





using ll = long long;

const ll mod = 1e9+7;
const int maxn = 1e6 + 5;



ll n,m,d;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);  cout.tie(0);

    cin>>n>>m>>d;
    double res = 0;
    if (d==0) {
	for (int i=0; i<m-1; i++) {
	    res += (1.0*n/(n*n));
	}
    } else {
	for (int i=0; i<m-1; i++) {
	    res += ((2.0*(n-d))/(n*n));
	}
    }


    cout<<fixed<<setprecision(9)<<res<<endl;    
    return 0;
}
