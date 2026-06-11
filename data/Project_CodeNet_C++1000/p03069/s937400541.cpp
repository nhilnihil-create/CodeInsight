#include <iostream>
#include <vector>
#include <string>
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
//#define NIL -1
//#define INFTY 1000000000000000000

int main(){
    LL n;
    string s;
    cin >> n;
    cin >> s;

    vector<LL> num_s(n+1);
    vector<LL> num_d(n+1);
    num_s[0]=0;
    for(LL i=1; i<=n; i++){
        if(s[i-1]=='#'){
            num_s[i]=num_s[i-1]+1;
        }else{
            num_s[i]=num_s[i-1];
        }
    }

    num_d[n]=0;
    for(LL i=n-1; i>=0; i--){
        if(s[i]=='.'){
            num_d[i]=num_d[i+1]+1;
        }else{
            num_d[i]=num_d[i+1];
        }
    }

    LL ans=n;
    for(LL i=0; i<=n; i++){
        //cout << num_s[i] << " " << num_d[i] << endl;
        ans=min(ans, num_s[i]+num_d[i]);
    }

    cout << ans << endl;

    return 0;
}
