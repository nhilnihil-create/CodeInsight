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
//#define MAX 200100
//#define NIL -1

int main() {
    int n;
    int k;
    int ans;

    cin >> n >> k;
    if(n%k==0){
        ans=0;
    }else{
        ans=1;
    }

    cout << ans << endl;

    return 0;
}