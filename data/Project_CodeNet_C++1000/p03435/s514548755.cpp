#include <iostream>
#include <iomanip>
typedef long long ll;
using namespace std;
const  ll INF = 1e9;
const  ll MOD = 1e9 + 7;
#define repi(i,n,init) for(ll i=init;i<(n);i++)

int main()
{
    int c[3][3];
    repi(i,3,0){
        repi(j,3,0){
            cin >> c[i][j];
        }
    }
    repi(i,101,-100){
        repi(j,101,-101){
            repi(k,101,-101){
                int cnt = 0;
                repi(l,3,0){
                    if(c[0][l] - i == c[1][l] - j && c[1][l] - j == c[2][l] - k && c[2][l] - k == c[0][l] - i)cnt++;
                }
                if(cnt == 3){
                    cout << "Yes" << endl;
                    return 0;
                }
            }
        }
    }
    cout << "No" << endl;
    return 0;
}