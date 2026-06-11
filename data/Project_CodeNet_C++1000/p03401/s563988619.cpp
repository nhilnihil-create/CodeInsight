#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>

#define _GLIBCXX_DEBUG
#define rep(i, n) for (int64_t i = 0; i < (int64_t)(n); i++)
using namespace std;
using vi = vector<int64_t>;
using vvi = vector<vi>;

int main(int argc, const char * argv[]) {
    // fasten cin
    cin.tie(0);
    ios::sync_with_stdio(false);
    // implement
    int64_t n;
    cin >> n;
    vi a(n+1);
    rep(i,n) cin >> a.at(i);
    a.at(n) = 0;
    int64_t sum = abs(a.at(0));
    rep(i,n-1){
        sum += abs(a.at(i+1) - a.at(i));
    }
    sum += abs(a.at(n-1));
    vi res(n);
    if((a.at(1) - a.at(0) >= 0 && a.at(0) >= 0) ||
       (a.at(1) - a.at(0) <= 0 && a.at(0) <= 0)){
        res.at(0) = sum;
    }else{
        res.at(0) = sum - (abs(a.at(1) - a.at(0)) + abs(a.at(0)))
        + abs(a.at(1));
    }
    for(int i=1; i<n; i++){
        if((a.at(i+1) - a.at(i) >= 0 && a.at(i) - a.at(i-1) >= 0) ||
           (a.at(i+1) - a.at(i) <= 0 && a.at(i) - a.at(i-1) <= 0)){
            res.at(i) = sum;
        }else{
            res.at(i) = sum - (abs(a.at(i+1) - a.at(i)) + abs(a.at(i) - a.at(i-1)))
            + abs(a.at(i+1) - a.at(i-1));
        }
    }
    rep(i,n) cout << res.at(i) << endl;
}
