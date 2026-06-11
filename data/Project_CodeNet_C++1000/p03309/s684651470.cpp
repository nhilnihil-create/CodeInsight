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
    VI a(n);
    rep(i,n){
        cin >> a[i];
        a[i] -= (i+1);
    }

    sort(a.begin(), a.end());
    int b;
    if(n%2==1){
        b = a[n/2];
    }else{
        b = (a[n/2] + a[n/2-1])/2;
    }

    ll ans=0;
    rep(i,n){
        ans += (ll)abs(a[i] - b);
    }

    cout << ans << endl;

	return 0;
}