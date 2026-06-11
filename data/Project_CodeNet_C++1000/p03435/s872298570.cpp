#include <bits/stdc++.h>
#define be(v) (v).begin(),(v).end()
#define pb(q) push_back(q)
typedef long long ll;
using namespace std;
const ll mod=1000000007, INF=(1LL<<60);
#define doublecout(a) cout<<fixed<<setprecision(10)<<a<<endl;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    int a[3][3];
    for(int i=0;i<3;i++){
    	for(int j=0;j<3;j++){
    		cin >> a[i][j];
    	}
    }
    int mi = 10000;
    for(int i=0;i<3;i++) mi = min(mi, a[0][i]);
    int b[3];
    for(int i=0;i<3;i++) {
    	b[i] = a[0][i] - mi;
    }
    for(int i=0;i<3;i++){
    	for(int j=0;j<3;j++){
    		a[i][j] -= b[j];
    	}
    }
    bool ok = true;
    for(int i=1;i<3;i++){
    	for(int j=0;j<2;j++){
    		if(a[i][j] != a[i][j+1]) ok = false;
    	}
    }
    if(ok) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}
