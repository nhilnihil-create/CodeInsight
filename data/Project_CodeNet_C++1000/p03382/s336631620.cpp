#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <cstdlib>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <utility>
#include <vector>
#define REP(i, n) for(int i = 0; i < (n); ++i)
typedef long long ll;
const ll MOD = 1000000007;
using namespace std;

int main(){
    int n; cin >> n;
    vector<int> a(n);
    REP(i, n) cin >> a[i];

    sort(a.begin(), a.end());
    int r = a[0]; double mid = a[n-1]/2.0;
    double dif = abs(mid - a[0]);
    REP(i, n-1){
        if(dif > abs(mid - a[i])){
            r = a[i];
            dif = abs(mid - a[i]);
        }
    }
    cout << a[n-1] << " " << r << endl;
    return 0;
}