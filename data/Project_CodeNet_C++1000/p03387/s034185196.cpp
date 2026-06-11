#include <iostream>
#include <cmath>
#include <string.h>
#include <iomanip>
#include <math.h>
#include <algorithm>
#include <vector>
#include <map>
#include <tuple>
using namespace std;

#define INF 100000000;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
typedef long long ll;
#define eps 1.0e-14;

int main(){
    int A,B,C;
    cin >> A >> B >> C;
    int M = max(max (A , B), C);
    int ans;
    if((A + B + C) % 2 == (3 * M) % 2){
        ans = ((3 * M) - (A + B + C)) / 2;
    }else{
        ans = ((3 * (M + 1)) - (A + B + C)) / 2;
    }
    cout << ans << endl;
    return 0;
}