#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); i++)
#define print(n) cout << n << endl
using namespace std;
using ll = long long;
 
int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    int N;
    cin >> N;

    double sum = 0.0;
    rep(i,N) {
        double x; cin >> x;
        string u; cin >> u;

        if (u == "JPY") sum += x;
        else sum += x * 380000.0;
    }

    cout << setprecision(20) << sum << endl;

    return 0;
}
