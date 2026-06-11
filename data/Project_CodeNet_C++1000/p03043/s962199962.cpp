#include <bits/stdc++.h>
#define rep(i, n) for (int i=0; i < (n); i++)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

int main() {
    int n, k;
    cin >> n >> k;
    double ans = 0;
    for (int i = 1; i <= n; i++){
        double score = i;
        double coin = 1.0/n;
        while (score < k){
            score *= 2;
            coin /= 2;
        };
        ans += coin;
    }; 
    cout << fixed << setprecision(15) << ans << endl;
}