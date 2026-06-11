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
    ll N;
    cin >> N;

    ll A[2][N];
    rep(i, N * 2){
        cin >> A[i / N][i % N];
    }

    ll sum[2][N];
    sum[0][0] = A[0][0];
    sum[1][0] = sum[0][0] + A[1][0];
    REP(i, N - 1){
        sum[0][i] = sum[0][i - 1] + A[0][i];
        sum[1][i] = max(sum[0][i], sum[1][i - 1]) + A[1][i];
    }

    cout << sum[1][N - 1] << endl;
    
    return 0;
}