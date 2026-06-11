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

    char S[H + 2][W + 2];
    rep(i, W + 2){
        S[0][i] = '.';
        S[H + 1][i] = '.';
    }
    rep(i, H + 2){
        S[i][0] = '.';
        S[i][W + 1] = '.';
    }
    REP(i, H){
        REP(j, W){
            cin >> S[i][j];
        }
    }

    ll count = 0;
    REP(i, H){
        REP(j, W){
            if(S[i][j] == '.'){
                count = 0;
                for(ll p = i - 1; p <= i + 1; p++){
                    for(ll q = j - 1; q <= j + 1; q++){
                        if(S[p][q] == '#'){
                            count++;
                        }
                    }
                }
                cout << count;
            }else{
                cout << '#';
            }
        }
        cout << endl;
    }
    
    return 0;
}