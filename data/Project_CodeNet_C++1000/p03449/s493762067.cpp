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
    int n;
    cin >> n;
    int a[2][n];
    for(int i=0;i<2;i++){
    	for(int j=0;j<n;j++){
    		cin >> a[i][j];
    	}
    }
    for(int i=1;i<n;i++){
    	a[0][i] += a[0][i-1];
    }
    a[1][0] += a[0][0];
    for(int i=1;i<n;i++){
    	a[1][i] += max(a[0][i], a[1][i-1]);
    }
    cout << a[1][n-1] << endl;
    return 0;
}
