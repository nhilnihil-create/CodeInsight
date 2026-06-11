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
    bool is_four=false;
    cin >> n;

    char s;
    for(LL i=0; i<n; i++){
        cin >> s;
        if(s=='Y'){
            is_four=true;
        }
    }

    if(is_four==true){
        cout << "Four" << endl;
    }else{
        cout << "Three" << endl;
    }

    return 0;
}
