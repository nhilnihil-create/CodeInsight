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
//#define MAX 100100
#define NIL -1
//#define INFTY 1000000000000000000

int main(){
    LL n;
    LL m;
    cin >> n >> m;
    vector<LL> x(n);
    vector<LL> y(n);
    vector<LL> z(n);
    for(LL i=0; i<n; i++){
        cin >> x[i] >> y[i] >> z[i];
    }

    LL ans=0;
    for(LL i=-1; i<=1; i+=2){
        for(LL j=-1; j<=1; j+=2){
            for(LL k=-1; k<=1; k+=2){
                vector<LL> d(n);
                for(LL l=0; l<n; l++){
                    d[l]=x[l]*i+y[l]*j+z[l]*k;
                }
                sort(d.begin(), d.end(), greater<LL>());
                LL tmp=0;
                for(LL l=0; l<m; l++){
                    tmp+=d[l];
                }
                ans=max(ans,tmp);
            }
        }
    }

    cout << ans << endl;

    return 0;
}
