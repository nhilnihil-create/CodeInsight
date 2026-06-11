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

LL llpow(LL x, LL n){
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
    cin >> n;
    vector<int> keta(60, 0);

    LL max_keta;
    LL tmp=0;

    if(n>=0){
        max_keta=0;
        tmp+=llpow(2, max_keta);
        while(n>tmp){
            max_keta+=2;
            tmp+=llpow(2, max_keta);
        }
    }else{
        max_keta=1;
        tmp-=llpow(2, max_keta);
        while(n<tmp){
            max_keta+=2;
            tmp-=llpow(2, max_keta);
        }
    }

    LL max_plus=0;
    LL min_minus=0;
    LL tmp_keta=0;
    while(tmp_keta<=max_keta){
        if(tmp_keta%2==0){
            max_plus+=llpow(2, tmp_keta);
        }else{
            min_minus-=llpow(2, tmp_keta);            
        }
        tmp_keta++;
    }

    tmp_keta=max_keta;
    while(tmp_keta>=0){
        if(tmp_keta%2==0){
            max_plus-=llpow(2, tmp_keta);
            if(n>max_plus){
                keta[tmp_keta]=1;
                n-=llpow(2, tmp_keta);
            }
        }else{
            min_minus+=llpow(2, tmp_keta);
            if(n<min_minus){
                keta[tmp_keta]=1;
                n+=llpow(2, tmp_keta);
                //cout << tmp_keta << " " << keta[tmp_keta] << endl;

            }            
        }
        //cout << tmp_keta << " " << n << endl;
        tmp_keta--;
    }

    for(int i=max_keta; i>=0; i--){
        cout << keta[i];
    }
    cout << endl;

    return 0;
}