#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <queue>
#include <set>
#include <algorithm>
#include <string>
#include <math.h>
#include <limits.h>
#include <stack>
#include <complex>
#include <stdlib.h>
#include <stdio.h>
#include <functional>
#include <cfloat>
#include <math.h>


#define fs first
#define sc second

using namespace std;

typedef long long ll;
typedef pair<ll, ll> P;


int main(){
    int Q;
    cin >> Q;
    for(int i = 0; i < Q; i++){
        ll a, b;
        cin >> a >> b;
        if(a > b){
            ll t = a;
            a = b;
            b = t;
        }
        if(a == b){
            cout << 2*a-2 << endl;
            continue;
        }
        else if(a+1 == b){
            cout << a+b-3 << endl;
            continue;
        }
        ll ret = sqrt(a*b);
        if(ret * ret == a*b){
            ret--;
        }
        if(ret*(ret+1) < a*b){
            cout << ret-1+ret << endl;
        }
        else{
            cout << ret*2-2 << endl;
        }
    }



    return 0;
}
