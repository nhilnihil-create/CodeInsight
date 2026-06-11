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
    int k;
    int ans=0;
    int tmp;
    cin >> k;
    tmp = k/2;
    if(k%2==0){
        ans = tmp*tmp;
    }else{
        ans = tmp*(tmp+1);
    }
    cout << ans << endl;

    return 0;
}