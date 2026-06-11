#include <algorithm>
#include <cassert>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;

#define rep(i, n) for(ll i = 0; i < n; i++)
#define REP(i, n) for(ll i = 1; i < n + 1; i++)
#define PI 3.14159265359
#define EPS 0.0000000001
#define MOD 1000000007
//cout << std::fixed << std::setprecision(15) << y << endl;


int main(){
    ll H, W;
    cin >> H >> W;

    char s[H + 2][W + 2];
    char S;
    rep(i, H + 2){
        rep(j, W + 2){
            s[i][j] = '.';
        }
    }
    REP(i, H){
        REP(j, W){
            cin >> S;
            s[i][j] = S;
        }
    }

    bool ifNo = false;
    REP(i, H){
        REP(j, W){
            if(s[i][j] == '#'){
                if(s[i - 1][j] == '.' && s[i][j - 1] == '.' && s[i][j + 1] == '.' && s[i + 1][j] == '.'){
                    ifNo = true;
                    break;
                }
            }
        }
        if(ifNo){
            break;
        }
    }

    if(ifNo){
        cout << "No" << endl;
    }else{
        cout << "Yes" << endl;
    }

    return 0;
}