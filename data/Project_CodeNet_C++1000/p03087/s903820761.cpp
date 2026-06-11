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
#define endl "\n"

using namespace std;

typedef long long ll;
typedef unsigned int uint;
typedef pair<int, int> P;


int main(){
    int n, q;   cin >> n >> q;
    string s;   cin >> s;
    vector<int> x(n, 0);
    for(int i = 1; i < n; i++){
        if(s[i] == 'C' && s[i-1] == 'A'){
            x[i] = 1;
        }
    }
    for(int i = 0; i < n-1; i++){
        x[i+1] += x[i];
    }

    for(int i = 0; i < q; i++){
        int l, r;   cin >> l >> r;
        l--; r--;
        if(l == 0){
            cout << x[r] << endl;
        }
        else{
            cout << x[r] - x[l] << endl;
        }
    }


    return 0;
}
