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
    LL n;
    LL a;
    LL b;
    LL ans=0;
    cin >> n >> a >> b;
    for(LL i=1; i<=n; i++){
        LL tmp=i;
        LL sum=0;
        while(tmp>0){
            sum+=tmp%10;
            tmp/=10;
        }
        //cout << i << sum << endl;
        if(sum>=a && sum<=b){
            ans+=i;
        }
    }

    cout << ans << endl;

    return 0;
}
