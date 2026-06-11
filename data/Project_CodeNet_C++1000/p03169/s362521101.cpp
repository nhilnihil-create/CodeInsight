#include <iostream>
#include <iomanip>
using namespace std;

int n, a, cnt[4];
double dp[305][305][305];

double f(int a, int b, int c){
    if (dp[a][b][c] > 0) return dp[a][b][c];
    if (!a && !b && !c) return dp[a][b][c] = 0;
    double ans = 0;
    if (a) ans += f(a-1, b+1, c)*a/(a+b+c);
    if (b) ans += f(a, b-1, c+1)*b/(a+b+c);
    if (c) ans += f(a, b, c-1)*c/(a+b+c);
    ans += (double)n/(a+b+c);
    return dp[a][b][c] = ans;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> a;
        cnt[a]++;
    }
    cout << fixed << setprecision(10) << f(cnt[3], cnt[2], cnt[1]) << "\n";
}
