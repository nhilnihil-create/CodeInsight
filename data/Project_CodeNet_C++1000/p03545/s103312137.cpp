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
    char N[4];
    cin >> N;

    ll X[4];
    rep(i, 4){
        X[i] = N[i] - '0';
    }

    ll sum = 0;
    for(ll bits = 0; bits < (1 << 3); bits++){
        sum = X[0];
        for(ll i = 0; i < 3; i++){
            if(((bits >> i) & (ll)1) == 0){
                sum += X[i + 1];
            }else{
                sum -= X[i + 1];
            }
        }
        if(sum == 7){
            cout << X[0];
            rep(i, 3){
                if(((bits >> i) & (ll)1) == 0){
                    cout << "+" << X[i + 1];
                }else{
                    cout << "-" << X[i + 1];
                }
            }
            cout << "=7" << endl;
            break;
        }
    }
    
    return 0;
}