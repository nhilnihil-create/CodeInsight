#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0;i<n;i++)
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0;}
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0;}

int main() {
    double n,k;
    cin >> n >>k;
    double ans = 0;
    for(int i = 1;i<=n;i++) {
        int x = i;
        int cnt = 0;
        while(x < k) {
            x *= 2;
            cnt++;
        }
        double a = 1/n;
        ans += a*pow(0.5,cnt);
    }
    cout << std::fixed << std::setprecision(15) << ans << endl;
}