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
#include <map>
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

vector<LL> num_div={1,3,5,15,25,75};
vector<LL> num_list;
LL num_lim;

LL dfs(LL idx, LL x){
    if(x==1){
        return 1;
    }else if(idx==num_lim){
        return 0;
    }
    LL ans=0;
    for(LL i=0; i<num_div.size(); i++){
        if(num_list[idx]+1<num_div[i]){
            continue;
        }
        if(x%num_div[i]==0){
            LL tmp=dfs(idx+1, x/num_div[i]);
            //cout << idx << " " << x << " " << num_div[i] << endl;
            ans+=tmp;
        }
    }

    return ans;
}

int main(){
    LL n;
    map<LL, LL> num;
    cin >> n;
    for(LL i=2; i<=n; i++){
        LL tmp=i;
        LL idx=2;
        while(tmp!=1){
            while(tmp%idx==0){
                num[idx]++;
                tmp/=idx;
            }
            idx++;
        }
    }

    for(auto i=num.begin(); i!=num.end(); i++){
        if(i->second>=2){
            num_list.push_back(i->second);
        }
    }
    num_lim=num_list.size();
    //for(LL i=0; i<num_lim; i++){
    //    cout << num_list[i] << endl;
    //}

    cout << dfs(0,75) << endl;

    return 0;
}
