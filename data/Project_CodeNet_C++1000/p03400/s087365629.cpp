#include <iostream>
#include <vector>
//#include <string>
//#include <algorithm>
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
    LL d;
    LL x;
    cin >> n;
    cin >> d >> x;
    vector<LL> a(n);
    for(LL i=0; i<n; i++){
        cin >> a[i];
    }
    LL ans=x;
    for(LL i=0; i<n; i++){
        for(LL j=1; j<=d; j++){
            if((j-1)%a[i]==0){
                ans++;
            }
        }
    }

    cout << ans << endl;

    return 0;
}
