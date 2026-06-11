#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
using ll = long long;
using VI = vector<int>;
using VVI = vector<vector<int>>;
using P = pair<int, int>;

int main(){
	int n,k;
    cin >> n >> k;
    
    ll ans;
    if(k%2 == 0){
        ll l = 2*n/k;
        ll o = (l+1)/2;
        ll e = l/2;
        ans = o*o*o + e*e*e;
    }else{
        ll l = n/k;
        ans = l*l*l;
    }

    cout << ans << endl;

	return 0;
}