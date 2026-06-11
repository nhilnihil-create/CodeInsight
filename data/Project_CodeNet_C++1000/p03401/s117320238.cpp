#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
using ll = long long;
using VI = vector<int>;
using VVI = vector<vector<int>>;
using P = pair<int, int>;

int main(){
	int n;
    cin >> n;
    VI a(n+2,0);
    rep(i,n) cin >> a[i+1];

    VI to(n+2,0), from(n+2,0);
    rep(i,n+1){
        to[i+1] = to[i] + abs(a[i+1] - a[i]); 
        int j = n-i;
        from[j] = from[j+1] + abs(a[j+1] - a[j]);
    }

    rep(i,n){
        int j = i+1;
        cout << (to[j-1] + abs(a[j+1] - a[j-1]) + from[j+1]) << endl;
    }


	return 0;
}