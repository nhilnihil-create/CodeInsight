#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <numeric>
#include <functional>
#include <map>
#include <queue>
#define REP(i,n) for(int (i)=0; (i)<(n); (i)++)
using namespace std;
using ll = long long;
ll MOD = 1e9+7;


int main(int argc, const char * argv[]) {    
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int n, a, b;
    cin >> n >> a >> b;
    cout << min(a,b) << " " << (a+b-n < 0 ? 0 : a+b-n) << endl;
    return 0;
}
