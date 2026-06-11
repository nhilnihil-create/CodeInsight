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
//#define MAX 200100
//#define NIL -1

int main() {
    int n;
    vector<LL> a;
    LL tmp_a;
    LL ans;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> tmp_a;
        a.push_back(tmp_a);
    }

    sort(a.begin(), a.end());
    ans = a[n-1]-a[0];
    cout << ans << endl;

    return 0;
}
