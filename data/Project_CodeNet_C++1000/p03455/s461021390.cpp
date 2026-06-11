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
    LL ab;
    cin >> a >> b;
    ab=a*b;
    if(ab%2==0){
        cout << "Even" << endl;
    }else{
        cout << "Odd" << endl;
    }

    return 0;
}
