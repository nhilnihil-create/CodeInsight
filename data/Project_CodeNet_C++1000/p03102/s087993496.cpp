#include <bits/stdc++.h>
using namespace std;
#define arep(i, x, n) for (int i = int(x); i < (int)(n); i++)
#define rep(i, n) for (long long i = 0; i < n; ++i)
#define pi 3.141592653589793
#define eps 0.00000001
#define INF 1e9 + 7
using ll = long long;

int main(){
    int n;
    int m;
    int c;
    cin >> n >> m >> c;

    int B[m];
    rep(i, m){
        cin >> B[i];
    }

    int A[n][m];
    rep(j, n){
        rep(i, m){
            cin >> A[j][i];
        }
    }

    int cnt = 0;
    rep(j, n){
        int sum = c;
        rep(i, m){
            sum += B[i] * A[j][i];
        }

        if(sum > 0){
            cnt = cnt + 1;
        }
    }

    cout << cnt << endl;
}