#include <iostream>
//#include <vector>
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
//#define INFTY 1000000000000000000

int main(){
    LL a;
    LL b;
    LL c;
    LL x;
    LL ans=0;
    cin >> a;
    cin >> b;
    cin >> c;
    cin >> x;
    for(LL i=0; i<=a; i++){
        for(LL j=0; j<=b; j++){
            LL tmp=x-500*i-100*j;
            if(tmp%50==0 && tmp/50<=c && tmp/50>=0){
                ans++;
            }
        }
    }

    cout << ans << endl;

    return 0;
}
