#include <bits/stdc++.h>
using namespace std;
#define FOR(i, a, b) for(int i=(a);i<(b);++i)
#define rep(i, n) FOR(i, 0, n)
#define whole(x) (x).begin(),(x).end()
#define UNIQUE(v) v.erase(unique(v.begin(), v.end()), v.end())
using ll = long long;
using P = pair<int, int>;
const int mod = 1000000007;

vector<int> prime;
int num[105];

void setPrime(int n) {
    for(int i=2; i<=n; i++) {
        bool ok = true;
        for (int j=2; j*j<=i; j++) {
            if (i%j==0) ok = false;
        }
        if (ok) prime.push_back(i);
    }
}



int main(){
    int n;
    cin >> n;
    ll ans = 0;
    setPrime(n);
    
    
    for (int i=2; i<=n; i++) {
        int v = i;
        for (int j:prime) {
            if (v==1) break;
            while (v%j==0) {
                v /= j;
                num[j]++;
            }
        }
    }
    rep(i, n+1) {
        //cout << num[i] << endl;
    }
    
    int num74 = 0;
    int num24 = 0;
    int num14 = 0;
    int num4 = 0;
    int num2 = 0;
    rep(i, n+1) {
        if (num[i]>=74) num74++;
        if (num[i]>=24) num24++;
        if (num[i]>=14) num14++;
        if (num[i]>=4) num4++;
        if (num[i]>=2) num2++;
    }
    ans += num74;
    ans += num24*(num2-1);
    ans += num14*(num4-1);
    ans += (num4*(num4-1)/2)*(num2-2);
    
    cout << ans << endl;
    
    return 0;
}
