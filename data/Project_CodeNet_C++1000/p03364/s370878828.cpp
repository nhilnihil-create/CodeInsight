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
#define sz(x) (int)x.size()
const int maxn = 10000001;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    string s[n] = {};
    f(n) {
        cin >> s[i];
    }
    int ans = 0;
    f(n) {
        int f = 0;
        fr(j,0,n) {
            fr(k,j+1,n) {
                if (s[j][k] != s[k][j]) {
                    f = 1;
                    break;
                }
            }
            if (f) {
                break;
            }
        }
        if (!f) {
            ans += n;
        }
        fr (j,0,n) {
            s[j] = s[j].substr(1) + s[j][0];
        }
    }
    cout << ans << '\n';
}  