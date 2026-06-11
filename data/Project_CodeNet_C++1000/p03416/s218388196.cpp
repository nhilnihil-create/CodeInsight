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

int main(){
    LL a;
    LL b;
    LL ans=0;
    vector<LL> num(5);
    cin >> a >> b;
    for(LL i=a; i<=b; i++){
        LL tmp=i;
        for(LL j=0; j<5; j++){
            num[j]=tmp%10;
            tmp/=10;
        }
        if(num[0]==num[4] && num[1]==num[3]){
            ans++;
        }
    }

    cout << ans << endl;

    return 0;
}
