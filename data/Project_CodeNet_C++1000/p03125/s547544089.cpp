#include <bits/stdc++.h>
using namespace std;
#define fo(x, n) for(int i = x; i <= n; i++)
#define all(x) x.begin(), x.end()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector <int> vi;
const int MOD = 1e9 + 7;
void solve(){
    int a, b;
    cin >> a >> b;
    cout << b + a * (b % a == 0 ? 1 : -1);
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0);
	int T = 1;
    //cin >> T;
    fo(1, T){
        solve();
    }
}


