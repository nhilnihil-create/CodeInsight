#include <iostream>
//#include <vector>
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

int main() {
    LL a;
    LL b;
    LL c;
    LL d;
    bool is_ok=false;
    cin >> a >> b >> c >> d;
    LL diff_ab = labs(a-b);
    LL diff_bc = labs(b-c);
    LL diff_ac = labs(a-c);
    if(diff_ac<=d){
        is_ok=true;
    }else if(diff_ab<=d && diff_bc<=d){
        is_ok=true;
    }

    if(is_ok==true){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }

    return 0;
}
