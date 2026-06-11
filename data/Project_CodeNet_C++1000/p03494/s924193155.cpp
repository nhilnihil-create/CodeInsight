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
//#define INFTY 1000000000000000000

int main(){
    LL n;
    cin >> n;
    vector<LL> a(n);
    for(LL i=0; i<n; i++){
        cin >> a[i];
    }

    LL ans=0;
    while(a[0]%2==0){
        ans++;
        a[0]/=2;
    }
    for(LL i=1; i<n; i++){
        LL tmp_ans=0;
        while(a[i]%2==0){
            tmp_ans++;
            a[i]/=2;
        }
        ans=min(ans, tmp_ans);
    }

    cout << ans << endl;

    return 0;
}
