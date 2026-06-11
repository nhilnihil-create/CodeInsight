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


#define fs first
#define sc second

using namespace std;

typedef long long ll;
typedef pair<ll, ll> P;

int size[300];
int size_depth[300];
int d[300];
int p[300];
vector<int> child[300];
int N, M, K;
int root = -1;


int main(){
    int N; cin >> N;
    ll a[201000], b[201000];
    ll res = 0;

    bool sam = true;
    ll mi = LONG_LONG_MAX;
    for(int i = 0; i < N; i++){
        cin >> a[i] >> b[i];
        if(a[i] != b[i]){
            sam = false;
        }
        if(a[i] > b[i]){
            mi = min(mi, b[i]);
        }
        res += b[i];
    }

    if(sam){
        cout << 0 << endl;
    }
    else{
        cout << res - mi << endl;
    }


    return 0;
}
