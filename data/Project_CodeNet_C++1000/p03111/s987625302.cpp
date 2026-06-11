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
#define MAX 10000100
//#define NIL -1

LL pow(LL x, LL n){
    LL ans = 1;
    while(n>0){
        if((n&1)==1){
            ans = ans * x;
        }
        x = x * x;
        n >>= 1;
    }
    return ans;
}

int main() {
    LL n;
    vector<LL> abc(3);
    cin >> n >> abc[0] >> abc[1] >> abc[2];
    vector<LL> l(n);
    vector<LL> l_sum(3);
    vector<LL> l_num(3);
    LL num=pow(4, n);
    LL min_ans=MAX;
    LL ans=0;

    for(LL i=0; i<n; i++){
        cin >> l[i];
    }

    for(LL i=0; i<num; i++){
        LL tmp=i;
        LL num_minus=0;
        LL num_plus=0;
        LL idx;
        for(LL j=0; j<3; j++){
            l_sum[j]=0;
            l_num[j]=0;
        }
        for(LL j=0; j<n; j++){
            idx=tmp%4;
            if(idx!=0){
                l_sum[idx-1]+=l[j];
                l_num[idx-1]++;
            }
            tmp = tmp >> 2;
        }
        //cout << l_num[0] << " " << l_num[1] << " " << l_num[2] << endl;
        if(l_num[0]==0 || l_num[1]==0 || l_num[2]==0){
            continue;
        }
        for(LL j=0; j<3; j++){
            if(abc[j]-l_sum[j]>0){
                num_plus+=(abc[j]-l_sum[j]);
            }else if(l_sum[j]-abc[j]>0){
                num_minus+=(l_sum[j]-abc[j]);
            }
        }
        ans=(l_num[0]+l_num[1]+l_num[2]-3)*10+num_plus+num_minus;
        if(min_ans>ans){
            min_ans=ans;
            //cout << i << " " << min_ans << " " << l_sum[0] << " " << l_sum[1] << " " << l_sum[2] << " " << l_num[0] << " " << l_num[1] << " " << l_num[2] << " " << num_plus << " " << num_minus << endl;
        }
    }

    cout << min_ans << endl;

    return 0;
}
