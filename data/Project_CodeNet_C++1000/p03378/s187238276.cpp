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
    LL m;
    LL x;
    cin >> n >> m >> x;
    vector<LL> a(n+1,0);
    LL tmp;
    LL ans_l=0;
    LL ans_r=0;
    for(LL i=0; i<m; i++){
        cin >> tmp;
        a[tmp]=1;
    }

    for(LL i=0; i<x; i++){
        ans_l+=a[i];
    }
    for(LL i=x+1; i<=n; i++){
        ans_r+=a[i];
    }
    if(ans_l<ans_r){
        cout << ans_l << endl;
    }else{
        cout << ans_r << endl;
    }

    return 0;
}
