#include <bits/stdc++.h>
#define ALL(A) (A).begin(), (A).end()
#define ll long long
#define rep(i, n) for (int i = 0; i < (n); i++)

const ll mod = 1e9 + 7;
const ll INF = -1 * ((1LL << 63) + 1);
const int inf = -1 * ((1 << 31) + 1);

using namespace std;

int main(void){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    string s;
    cin >> s;
    int l = 0 , r = s.size() - 1;
    int ans = 0;
    while(l<r){
        if(s[l] == s[r]){
            l++;
            r--;
        }else if(s[l]=='x'){
            l++;
            ans++;
        }else if(s[r]=='x'){
            r--;
            ans++;
        }else {
            cout << -1 << endl;
            return 0;
        }
    }
    cout << ans << endl;
}