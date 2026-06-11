#include <iostream>
//#include <vector>
#include <string>
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
    string s;
    LL ans=700;
    cin >> s;
    for(LL i=0; i<3; i++){
        if(s[i]=='o'){
            ans+=100;
        }
    }

    cout << ans << endl;

    return 0;
}
