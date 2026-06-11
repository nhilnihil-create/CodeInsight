#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define pb push_back
#define F first
#define S second
#define all(x) x.begin(), x.end()
const int maxn = 1e6 + 5;


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    string s;
    cin >> s;
    int t;
    cin >> t;
    while(t--) {
        ll D = 0, M = 0, DM = 0;
        int k;
        cin >> k;
        ll ans = 0;
        f(k) {
            if (s[i] == 'C') {
                ans += DM;
            }
            else if(s[i] == 'D') {
                D++;
            }
            else if(s[i] == 'M') {
                M++;
                DM += D;
            }
        }
        for (int i = k ; i < n ; i++) {
            if (s[i - k] == 'D') {
                DM -= M;
                D--;
            }
            else if(s[i-k] == 'M') {
                M--;
            }
            if (s[i] == 'C') {
                ans += DM;
            }
            else if(s[i] == 'D') {
                D++;
            }
            else if(s[i] == 'M') {
                M++;
                DM += D;
            }
        }
        cout << ans << '\n';
    }
}