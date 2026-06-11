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
//#define NIL -1
//#define INFTY 1000000000000000000

int main(){
    LL n;
    cin >> n;
    vector<vector<LL>> a_bin(n+1,vector<LL>(20, 0));
    vector<LL> a(n);
    for(LL i=0; i<n; i++){
        cin >> a[i];
    }
    LL tmp;
    for(LL i=1; i<=n; i++){
        tmp=a[i-1];
        for(LL j=0; j<20; j++){
            a_bin[i][j]=tmp%2;
            a_bin[i][j]+=a_bin[i-1][j];
            tmp/=2;
        }
    }

    LL end_point=1;
    LL ans=0;
    for(LL i=0; i<=n; i++){
        while(true){
            bool is_ok=true;
            for(LL j=0; j<20; j++){
                if(a_bin[end_point][j]-a_bin[i][j]>1){
                    is_ok=false;
                }
            }
            if(is_ok==false){
                ans+=(end_point-1-i);
                break;
            }else if(end_point==n){
                ans+=end_point-i;
                break;
            }else{
                end_point++;
            }
        }
    }

    cout << ans << endl;

    return 0;
}
