#include <iostream>
#include <vector>
//#include <string>
#include <algorithm>
//#include <math.h>
//#include <queue>
//#include <stack>
//#include <iomanip>

// sometimes used
//#include <set>
//#include <map>
//#include <numeric>
//#include <list>
//#include <deque>
//#include <unordered_map>

typedef long long LL;
//typedef long double LD;
using namespace std;
 
//#define MOD 1000000007
//#define MAX 100100
//#define NIL -1

int main() {
    vector<LL> a(3);
    LL k;
    LL ans;
    cin >> a[0] >> a[1] >> a[2];
    cin >> k;

    sort(a.begin(), a.end());
    for(LL i=0; i<k; i++){
        a[2]*=2;
    }
    ans=a[0]+a[1]+a[2];
    cout << ans << endl;

    return 0;
}
