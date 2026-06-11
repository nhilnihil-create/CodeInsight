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
//typedef long long LL;
//typedef long double LD;
using namespace std;
 
//#define MOD 1000000007
//#define MAX 100100
//#define NIL -1

int main() {
    int a;
    int b;
    int tmp;
    cin >> a >> b;
    tmp=a*b;
    if(tmp%2!=0){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }

    return 0;
}