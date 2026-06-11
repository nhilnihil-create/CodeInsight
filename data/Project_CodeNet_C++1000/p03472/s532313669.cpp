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
//#include <map>
//#include <numeric>
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
    int n;
    LL h;
    vector<LL> a;
    vector<LL> b;
    LL tmp_a;
    LL tmp_b;
    cin >> n >> h;
    for(int i=0; i<n; i++){
        cin >> tmp_a >> tmp_b;
        a.push_back(tmp_a);
        b.push_back(tmp_b);
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    auto itr=lower_bound(b.begin(), b.end(), a[n-1]+1);
    int idx=distance(b.begin(), itr);
    int k_throw=n-1;
    LL ans=0;
    while(h>0){
        if(k_throw>=idx){
            h-=b[k_throw];
            k_throw--;
            ans++;
        }else{
            if(h%a[n-1]==0){
                ans+=h/a[n-1];
            }else{
                ans+=h/a[n-1]+1;
            }
            h=0;
        }
    }

    cout << ans << endl;

    return 0;
}
