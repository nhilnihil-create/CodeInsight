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
    LL n;
    LL x;
    cin >> n >> x;
    vector<LL> m(n);
    for(LL i=0; i<n; i++){
        cin >> m[i];
        x-=m[i];
    }

    sort(m.begin(), m.end());
    while(x>=m[0]){
        x-=m[0];
        n++;
    }

    cout << n << endl;

    return 0;
}
