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


#define fs first
#define sc second

using namespace std;

typedef long long ll;
typedef pair<ll, int> P;

ll mypow(int k, int n){
    ll res = 1;
    while(n > 0){
        res *= k;
        n--;
    }
    return res;
}

ll a[1000000];
pair<P, P> res[1000000];

int main(){
    int N;
    cin >> N;
    for(int i = 0; i < mypow(2, N); i++){
        cin >> a[i];
    }

    res[1] = pair<P, P>(P(a[0], 0), P(a[1], 1));
    res[2] = pair<P, P>(P(a[0], 0), P(a[2], 2));
    for(int k = 3; k < mypow(2, N); k++){
        set<P, greater<P> > s;
        s.insert(P(a[k], k));
        s.insert(P(a[0], 0));
        for(int i = 0; i < 18; i++){
            if(((1 << i) & k) > 0){
                int bef = k^(1<<i);
                s.insert(res[bef].first);
                s.insert(res[bef].second);
            }
        }
        P x1, x2;
        auto itr = s.begin();
        x1 = *itr; itr++;
        x2 = *itr;
        res[k] = pair<P, P>(x1, x2);
    }

    /*for(int k = 1; k < mypow(2, N); k++){
        cout << k << " " << res[k].first.first << " " << res[k].second.first << endl;
    }*/

    ll res2[1000000];
    res2[1] = a[0] + a[1];
    for(int k = 2; k < mypow(2, N); k++){
        ll res_tmp = res[k].first.first + res[k].second.first;
        res2[k] = max(res_tmp, res2[k-1]);
    }
    for(int k = 1; k < mypow(2, N); k++){
        cout << res2[k] << endl;
    }


    return 0;

}
