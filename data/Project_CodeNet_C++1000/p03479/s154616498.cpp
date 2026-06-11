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
//#define MAX 200100
//#define NIL -1

int main() {
    LL x;
    LL y;
    int ans=1;
    cin >> x >> y;
    while(true){
        x*=2;
        if(y>=x){
            ans++;
        }else{
            break;
        }
    }

    cout << ans << endl;

    return 0;
}