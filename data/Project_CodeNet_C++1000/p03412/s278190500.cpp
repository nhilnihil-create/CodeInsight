#include <algorithm>
#include <cassert>
#include <cctype>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstring>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <vector>
#include <bitset>
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define show(x) cout << #x << " = " << (x) << endl;
using namespace std;
using ll = long long;
using pii = pair<int,int>;
int n;
int get(vector<int>a,vector<int>b,const int k){
    int res = 0;
    rep(i,n){
        a[i] %= (1<<(k+1));
        b[i] %= (1<<(k+1));
    }
    sort(b.begin(),b.end());
    const int c = 1<<k;
    for(auto x:a){
        res += (int)(lower_bound(b.begin(),b.end(),2*c-x)-lower_bound(b.begin(),b.end(),c-x));
        res += (int)(lower_bound(b.begin(),b.end(),4*c-x)-lower_bound(b.begin(),b.end(),3*c-x));
    }
    return res;
}
int main(){
    cin >> n;
    int ans = 0;
    vector<int>a(n),b(n);
    rep(i,n){
        cin >> a[i];
    }
    rep(i,n){
        cin >> b[i];
    }
    for(int i = 0; i <= 28; i++){
        if(get(a,b,i)%2){
            ans += 1<<i;
        }
    }
    cout << ans << endl;
}