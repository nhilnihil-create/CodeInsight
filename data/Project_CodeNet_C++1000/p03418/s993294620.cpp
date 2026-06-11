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

int main(){
    LL n;
    LL k;
    LL ans=0;
    cin >> n >> k;
    LL tmp;
    LL res;
    for(LL i=k+1; i<=n; i++){
        tmp=n/i;
        res=n%i;
        if(k==0){
            ans+=n;
        }else{
            if(res>=k){
                ans+=res-(k-1);
            }
            if(tmp>=1){
                ans+=tmp*(i-1-(k-1));
            }
        }
        //cout << ans << endl;
    }

    cout << ans << endl;


    return 0;
}
