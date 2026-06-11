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
typedef pair<ll, ll> P;

int main(){
    int n;  cin >> n;
    vector<ll> a(n);
    vector<ll> b(n);
    map<ll, int> mp;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        if(mp.find(a[i]) == mp.end()){
            mp[a[i]] = 1;
        }
        else{
            mp[a[i]]++;
        }
    }

    sort(a.begin(), a.end());

    int res = 0;
    for(int i = n-1; i >= 0; i--){
        ll x = 1;
        if(mp[a[i]] == 0)   continue;

        while(x <= a[i]){
            x *= 2;
        }
        b[i] = x - a[i];
        if(b[i] == a[i]){
            if(mp[a[i]] >= 2){
                mp[a[i]] -= 2;
                res++;
            }
        }
        else{
            if(mp[b[i]] >= 1){
                res++;
                mp[a[i]]--;
                mp[b[i]]--;
            }
        }
    }

    cout << res << endl;



    return 0;
}
