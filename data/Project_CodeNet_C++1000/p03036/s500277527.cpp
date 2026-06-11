#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep2(i, x ,n) for(int i = x; i < n; i++)
#define repr(i, n) for(int i = n; i >= 0; i--)
#define INF 2e9
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
int main(){
    int r,d,x[15];
    cin >> r >> d >> x[0];
    rep(i,10){
        x[i+1] = r*x[i]-d;
        cout << x[i+1] << endl;
    }
	return 0;
}