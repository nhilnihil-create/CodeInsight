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

int main() {
    LL d;
    LL g;
    cin >> d >> g;
    vector<LL> p(d);
    vector<LL> c(d);
    LL total=0;

    for(LL i=0; i<d; i++){
        cin >> p[i] >> c[i];
        total+=p[i];
    }

    vector<vector<LL>> dp(d, vector<LL>(total+1, NIL));
    dp[0][0]=0;

    for(LL i=1; i<=p[0]; i++){
        if(i==p[0]){
            dp[0][i]=dp[0][0]+i*100+c[0];
        }else{
            dp[0][i]=dp[0][0]+i*100;            
        }
    }

    total=p[0];
    for(LL i=1; i<d; i++){
        for(LL j=0; j<=total; j++){
            for(LL k=0; k<=p[i]; k++){
                LL score;
                if(k<p[i]){
                    score=dp[i-1][j]+(i+1)*100*k;
                }else{
                    score=dp[i-1][j]+(i+1)*100*k+c[i];
                }
                if(dp[i][j+k]==NIL || dp[i][j+k]<score){
                    dp[i][j+k]=score;
                }
                //cout << i << " " << j << " " << k << " " << score << endl;
            }
        }
        total+=p[i];
    }

    LL ans=0;
    for(LL i=0; i<=total; i++){
        //cout << dp[d-1][i] << endl;
        if(dp[d-1][i]>=g){
            ans=i;
            break;
        }
    }

    cout << ans << endl;

    return 0;
}
