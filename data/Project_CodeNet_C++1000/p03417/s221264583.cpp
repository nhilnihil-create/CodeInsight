#include <iostream>
//#include <set>
//#include <map>
//#include <iomanip>
//#include <algorithm>
//#include <numeric>
//#include <queue>
//#include <stack>
//#include <math.h>
//#include <vector>
//#include <string>
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
    LL n;
    LL m;
    LL tmp;
    LL ans;
    cin >> n >> m;
    if(m>n){
        tmp=n;
        n=m;
        m=tmp;
    }
    if(m==1){
        if(n==1){
            ans=1;
        }else if(n==2){
            ans=0;
        }else{
            ans=n-2;
        }
    }else if(m==2){
        ans=0;
    }else{
        ans=(n-2)*(m-2);
    }

    cout << ans << endl;

    return 0;
}