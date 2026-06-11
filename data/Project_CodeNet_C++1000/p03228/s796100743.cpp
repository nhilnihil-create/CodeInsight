#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < (n); ++i)
#define REPR(i, n) for (int i = n; i >= 0; --i)
#define FOR(i, n, m) for (int i = m; i < n; i++)
#define INF 1e9
#define ALL(v) v.begin(), v.end()

typedef long long ll;
/**
 * C問以降は ll を使う.
 * double型にするのを忘れない.
 * nC2の求め方 (1/2)*n*(n-1)
 * vector<型> 変数名(要素数, 初期値)
 */
int main()
{
    ll A, B, K;
    cin >> A >> B >> K;
    ll i = 0;
    while(K--) {
        if(i % 2 == 0) {
            if(A % 2 == 1) {
                --A;
            } else {

            }
            A /= 2;
            B += A;
        } else {
            if(B % 2 == 1) {
                --B;
            }
                B /= 2;
                A += B;
            
        }
        i++;
    }
    cout << A << " " << B << endl;
    return 0;
}