#include <iostream>
#include <vector>
//#include <string>
#include <algorithm>
//#include <math.h>
//#include <queue>
//#include <stack>
//#include <iomanip>

// sometimes used
#include <set>
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
    LL k;
    cin >> n >> k;
    vector<LL> v(n);
    for(LL i=0; i<n; i++){
        cin >> v[i];
    }

    LL lim=min(n,k);
    LL ans=0;
    LL sum;
    for(LL i=0; i<=lim; i++){
        for(LL j=0; j<=i; j++){
            sum=0;
            multiset<LL> get_val;
            for(LL l=0; l<=j; l++){
                if(l==0){
                    continue;
                }
                sum+=v[l-1];
                get_val.insert(v[l-1]);
                //cout << "left " << v[l-1] << " " << sum << endl;
            }
            for(LL l=0; j+l<=i; l++){
                if(l==0){
                    continue;
                }
                sum+=v[n-l];
                get_val.insert(v[n-l]);
                //cout << "right " << v[n-l] << " " << sum << endl;
            }
            LL tmp=k-i;
            while(tmp>0){
                auto itr=get_val.begin();
                if(*itr>=0){
                    break;
                }
                sum-=*itr;
                //cout << "erase " << *itr << " " << sum << endl;
                get_val.erase(itr);
                tmp--;
            }
            //cout << sum << endl;
            ans=max(ans,sum);
        }
    }

    cout << ans << endl;


    return 0;
}
