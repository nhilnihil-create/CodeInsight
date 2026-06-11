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
    string S;
    cin >> S;

    ll zeroStart = 0;
    ll oneStart = 0;
    rep(i, S.size()){
        if(i % 2 == 0){
            if(S[i] == '0'){
                oneStart++;
            }else{
                zeroStart++;
            }
        }else{
            if(S[i] == '0'){
                zeroStart++;
            }else{
                oneStart++;
            }
        }
    }

    cout << min(zeroStart, oneStart) << endl;

    return 0;
}