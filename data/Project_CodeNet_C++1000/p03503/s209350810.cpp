#include <iostream>
#include <algorithm>
#include <bitset>
#include <math.h>
#include <string>
#include <map>
#include <vector>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define rep(i, n) for (int i = 0; i < n; i++)
#define LargeNum 1000000007
typedef pair <double, double> P;

int main(){
    int N, ans = -1000000001, tmp;
    cin >> N;
    bool F[N][5][2];
    int P[N][11];
    int count[N];
    bitset<10> b;
    rep(i, N){
        rep(j, 5){
            cin >> F[i][j][0] >> F[i][j][1];
        }
    }
    rep(i, N){
        rep(j, 11){
            cin >> P[i][j];
        }
    }
    for (int i=1; i<pow(2, 10); i++){
        rep(mise, N) count[mise] = 0;
        b = i;
        rep(yo, 5){
            rep(ji, 2){
                if(b[yo*2 + ji]==1){
                    rep(mise, N){
                        if(F[mise][yo][ji] == 1) count[mise] ++;
                    }
                }
            }
        }
        tmp = 0;
        rep(mise, N){
            tmp += P[mise][count[mise]];
        }
        if (ans < tmp) ans = tmp;
    }
    cout << ans << endl;
    return 0;
}
