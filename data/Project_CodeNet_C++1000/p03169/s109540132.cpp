#include <bits/stdc++.h>
using namespace std;

template<typename T>
void out(T x) { cout << x << endl; exit(0); }
#define watch(x) cout << (#x) << " is " << (x) << endl




typedef long long ll;
const ll mod = 1e9+7;
const int maxn = 333;



int n;
int a[maxn];



double dp[301][301][301];


double solve(int zero, int one, int two) {
    //cout<<state[0]<<" "<<state[1]<<" "<<state[2]<<" "<<state[3]<<endl;
    if (zero==n) return 0;
    if (dp[zero][one][two] > -0.5) return dp[zero][one][two];

    double num = n;

    if (one>0) {
	num += one*solve(zero+1,one-1,two);
    }
    if (two>0) {
	num += two*solve(zero,one+1,two-1);
    }
    
    int three = n-zero-one-two;
    if (three>0) {
	num += three*solve(zero,one,two+1);
    }

    double den = n-zero;
    return dp[zero][one][two] = (num/den);
	    
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);  cout.tie(0);
    cin>>n;
    vector<int> f(3);
    for (int i=0; i<n; i++) {
	cin>>a[i];
	if (a[i]<3) f[a[i]]++;
    }
    for (int i=0; i<301; i++) {
	for (int j=0; j<301; j++) {
	    for (int k=0; k<301; k++) {
		dp[i][j][k]=-1;
	    }
	}
    }

    solve(f[0],f[1],f[2]);

    cout<<fixed<<setprecision(12)<<dp[f[0]][f[1]][f[2]]<<endl;

    return 0;
}
