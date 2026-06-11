#include <iostream>
//#include <vector>
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
    LL a;
    LL b;
    LL c;
    LL d;
    cin >> a >> b >> c >> d;
    LL ans=min(a,b)+min(c,d);
    cout << ans << endl;

    return 0;
}
