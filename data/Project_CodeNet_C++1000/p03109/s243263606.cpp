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

    ll y, m, d;
    y = (S[0] - '0') * 1000 + (S[1] - '0') * 100 + (S[2] - '0') * 10 + (S[3] - '0');
    m = (S[5] - '0') * 10 + (S[6] - '0');
    d = (S[8] - '0') * 10 + (S[9] - '0');

    if(y > 2019){
        cout << "TBD" << endl;
    }else if(y == 2019 && m > 4){
        cout << "TBD" << endl;
    }else{
        cout << "Heisei" << endl;
    }

    return 0;
}