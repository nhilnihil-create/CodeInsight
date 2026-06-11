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

//typedef long long LL;
//typedef long double LD;
using namespace std;
 
//#define MOD 1000000007
//#define MAX 200100
//#define NIL -1

int main() {
    vector<int> a(3);
    int ans=0;
    cin >> a[0] >> a[1] >> a[2];
    sort(a.begin(),a.end());

    ans = (a[1]-a[0])+(a[2]-a[1]);
    cout << ans << endl;

    return 0;
}
