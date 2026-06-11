#include <iostream>
//#include <set>
//#include <map>
//#include <iomanip>
//#include <algorithm>
//#include <numeric>
//#include <queue>
//#include <stack>
#include <math.h>
#include <vector>
//#include <string>
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
    LL n;
    vector<LL> a;
    LL tmp_a;
    LL orig=0;
    LL ans;
    cin >> n;
    a.push_back(0);
    for(int i=0; i<n; i++){
        cin >> tmp_a;
        a.push_back(tmp_a);
    }
    a.push_back(0);
    for(int i=0; i<a.size()-1; i++){
        orig+=(int)abs(a[i]-a[i+1]);
    }
    for(int i=1; i<=n; i++){
        ans=orig-(int)abs(a[i-1]-a[i])-(int)abs(a[i]-a[i+1]);
        ans+=(int)abs(a[i-1]-a[i+1]);
        cout << ans << endl;
    }

    return 0;
}