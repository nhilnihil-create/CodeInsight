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
    ll A, B, C, X;
    cin >> A >> B >> C >> X;

    ll ans = 0;
    ll Acount = 0;
    ll Bcount = 0;
    ll Ccount = 0;
    while(X - Acount * 500 >= 0 && Acount <= A){
        Bcount = 0;
        while(X - Acount * 500 - Bcount * 100 >= 0 && Bcount <= B){
            Ccount = (X - Acount * 500 - Bcount * 100) / 50;
            if(Ccount <= C){
                ans++;
            }
            Bcount++;
        }
        Acount++;
    }

    cout << ans << endl;
    
    return 0;
}