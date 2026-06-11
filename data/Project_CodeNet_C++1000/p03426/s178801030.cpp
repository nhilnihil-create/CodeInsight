#include <iostream>
#include <vector>
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
#define NIL -1
//#define INFTY 1000000000000000000

LL labs(LL x){
    if(x>0){
        return x;
    }else{
        return -1*x;
    }
}

int main(){
    LL h;
    LL w;
    LL d;
    LL q;
    cin >> h >> w >> d;
    LL a;
    vector<LL> x(h*w);
    vector<LL> y(h*w);
    for(LL i=0; i<h; i++){
        for(LL j=0; j<w; j++){
            cin >> a;
            a--;
            x[a]=i;
            y[a]=j;
        }
    }
    cin >> q;
    vector<LL> l(q);
    vector<LL> r(q);
    for(LL i=0; i<q; i++){
        cin >> l[i] >> r[i];
        l[i]--;
        r[i]--;
    }

    vector<LL> dp(h*w);
    for(LL i=0; i<d; i++){
        dp[i]=0;
    } 

    for(LL i=0; i<d; i++){
        LL tmp=i;
        while(tmp+d<h*w){
            dp[tmp+d]=dp[tmp]+labs(x[tmp+d]-x[tmp])+labs(y[tmp+d]-y[tmp]);
            tmp+=d;
        }
    }

    for(LL i=0; i<q; i++){
        cout << dp[r[i]]-dp[l[i]] << endl;
    }

    return 0;
}
