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
#include <numeric>
#include <string.h>
#include <sys/time.h>
#include <random>


#define fs first
#define sc second

using namespace std;

typedef long long ll;
typedef unsigned int uint;
typedef pair<ll, ll> P;


int main(){
    ll m, k;   cin >> m >> k;
    if(m == 1){
        if(k == 0){
            cout << "0 0 1 1" << endl;
        }
        else{
            cout << -1 << endl;
        }
        return 0;
    }

    int ma = (1 << m) - 1;
    if(k > ma){
        cout << -1 << endl;
        return 0;
    }
    vector<P> res;
    for(int i = 0; i <= ma; i++){
        int x = k ^ i;
        if(i <= x){
            res.emplace_back(P(i, x));
        }
    }

    for(auto p: res){
        cout << p.fs << " " << p.sc << " ";
    }
    if(k > 0) {
        for (auto p: res) {
            cout << p.sc << " " << p.fs << " ";
        }
    }
    cout << endl;



    return 0;
}
