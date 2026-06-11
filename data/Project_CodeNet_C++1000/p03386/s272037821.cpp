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

int main() {
    LL a;
    LL b;
    LL k;
    cin >> a >> b >> k;
    if(b-a<=2*(k-1)){
        for(LL i=a; i<=b; i++){
            cout << i << endl;
        }
    }else{
        for(LL i=a; i<a+k; i++){
            cout << i << endl;
        }
        for(LL i=b-k+1; i<=b; i++){
            cout << i << endl;
        }
    }

    return 0;
}
