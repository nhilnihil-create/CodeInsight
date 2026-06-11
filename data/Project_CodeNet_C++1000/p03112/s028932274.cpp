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
#define MAX 10010000000
//#define NIL -1
//#define INFTY 1000000000000000000

LL labs(LL x){
    if(x>0){
        return x;
    }else{
        return x*(-1);
    }
}

int main(){
    LL a;
    LL b;
    LL q;
    cin >> a >> b >> q;
    vector<LL> s(a);
    vector<LL> t(b);
    vector<LL> x(q);
    for(LL i=0; i<a; i++){
        cin >> s[i];
    }
    for(LL i=0; i<b; i++){
        cin >> t[i];
    }
    for(LL i=0; i<q; i++){
        cin >> x[i];
    }
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());
    LL tmp0;
    LL tmp1;
    LL tmp2;
    LL tmp3;
    for(LL i=0; i<q; i++){
        auto itr_s=lower_bound(s.begin(), s.end(), x[i]);
        auto itr_t=lower_bound(t.begin(), t.end(), x[i]);
        LL dist_s=distance(s.begin(), itr_s);
        LL dist_t=distance(t.begin(), itr_t);
        if(dist_s!=0){
            if(dist_t!=t.size()){
                tmp0=min(labs(x[i]-s[dist_s-1]),labs(t[dist_t]-x[i]))+labs(t[dist_t]-s[dist_s-1]);
            }else{
                tmp0=2*MAX;
            }
            if(dist_t!=0){
                tmp1=x[i]-min(s[dist_s-1], t[dist_t-1]);
            }else{
                tmp1=2*MAX;
            }
        }else{
            tmp0=2*MAX;
            tmp1=2*MAX;
        }
        if(dist_s!=s.size()){
            if(dist_t!=t.size()){
                tmp2=max(s[dist_s],t[dist_t])-x[i];
            }else{
                tmp2=2*MAX;
            }
            if(dist_t!=0){
                tmp3=min(labs(x[i]-t[dist_t-1]),labs(s[dist_s]-x[i]))+labs(s[dist_s]-t[dist_t-1]);
            }else{
                tmp3=2*MAX;
            }
        }else{
            tmp2=2*MAX;
            tmp3=2*MAX;
        }
        //cout << dist_s << " " << dist_t << endl;
        //cout << tmp0 << " " << tmp1 << " " << tmp2 << " " << tmp3 << endl;
        cout << min(min(tmp0,tmp1),min(tmp2,tmp3)) << endl;
    }

    return 0;
}
