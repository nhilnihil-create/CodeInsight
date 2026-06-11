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
    cin>>n;
    double T, A;
    cin>>T>>A;
    double dist = 1e9;
    int ans=-1;
    for (int i=1; i<=n; i++) {
	double x;
	cin>>x;
	double res = T-x*0.006;
	if (abs(A-res) < dist) {
	    ans=i;
	    dist = abs(A-res);
	}
    }

    cout<<ans<<endl;
    
    
    return 0;
}
