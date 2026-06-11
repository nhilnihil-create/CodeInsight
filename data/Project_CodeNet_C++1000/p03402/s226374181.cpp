#include <iostream>
#include <iomanip>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <tuple>
#include <cstring>
#include <functional>
using namespace std;
typedef long long ll;
typedef pair<long long, long long> P;
#define rep(i, n) for(long long i=0; i<n; i++)
#define reps(i, s, e) for(long long i=s; i<e; i++)
#define repr(i, n) for(long long i=n-1; i>=0; i--)
#define reprs(i, s, e) for(long long i=e-1; i>=s; i--)

int main(){

    cin.tie(0);
    ios::sync_with_stdio(false);

    int a, b; cin >> a >> b;
    int h = 100, w = 100;

    char mat[h][w];

    rep(i, h){
        if(i < h/2){
            rep(j, w){
                mat[i][j] = '#';
            }
        }
        else{
            rep(j, w){
                mat[i][j] = '.';
            }
        }
    }

    int a_add = a - 1;
    int b_add = b - 1;

    int i = 0, j = 0;
    rep(k, a_add){
        mat[i][j] = '.';
        j += 2;
        if(j >= w){
            i += 2;
            j  = 0;
        }
    }

    i = h-1, j = w-1;
    rep(k, b_add){
        mat[i][j] = '#';
        j -= 2;
        if(j < 0){
            i -= 2;
            j  = w-1;
        }
    }

    cout << 100 << " " << 100 << endl;

    rep(i, h){
        rep(j, w){
            cout << mat[i][j];
        }
        cout << endl;
    }

    return 0;
}