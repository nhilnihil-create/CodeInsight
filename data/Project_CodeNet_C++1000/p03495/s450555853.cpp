#include <iostream>
#include <vector>
//#include <string>
#include <algorithm>
//#include <math.h>
//#include <queue>
//#include <stack>
//#include <iomanip>

// sometimes used
//#include <set>
#include <map>
//#include <numeric>
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
    int tmp_a;
    int ans=0;
    vector<int> a(200010, 0);
    cin >> n >> k;
    for(int i=0; i<n; i++){
        cin >> tmp_a;
        a[tmp_a]++;
    }

    sort(a.begin(),a.end(),greater<int>());
    for(int i=k; i<a.size(); i++){
        ans+=a[i];
    }

    cout << ans << endl;

    return 0;
}