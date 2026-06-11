#include <bits/stdc++.h>
using namespace std;
#define fo(x, n) for(int i = x; i <= n; i++)
#define all(x) x.begin(), x.end()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector <int> vi;
const int MOD = 1e9 + 7;
void solve(){
    int a[5];
    cin >> a[0] >> a[1] >> a[2] >> a[3] >> a[4];
    sort(a, a + 5);
    int k;
    cin >> k;
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            if(abs(a[i] - a[j]) > k){
                cout << ":(";
                return;
            }
        }
    }
    cout << "Yay!";
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0);
	int T = 1;
    //cin >> T;
    fo(1, T){
        solve();
    }
}


