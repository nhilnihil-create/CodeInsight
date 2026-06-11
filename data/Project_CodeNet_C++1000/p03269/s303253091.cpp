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
#define show(x) cerr << #x << " = " << (x) << endl;
using namespace std;
using ll = long long;
using pii = pair<int,int>;
/*
 
 1->2->3->4
 
 */
struct edge{
    int a,b,c;
    edge(int a,int b,int c):a(a),b(b),c(c){}
};
ostream &operator<<(ostream &os, edge x){
    cout << x.a << " " << x.b << " " << x.c;
    return os;
}
int main(){
    int L;
    cin >> L;
    vector<edge>ans;
    int n = 32-__builtin_clz(L);
//    show(n);
    rep(i,n-1){
        ans.emplace_back(i+1,i+2,0);
        ans.emplace_back(i+1,i+2,1<<i);
    }
//    show(L);
    for(int i = n; i >= 0; i--){
        if(L-(1<<(n-1))>=(1<<i)){
            ans.emplace_back(i+1,n,L-(1<<i));
            L -= (1<<i);
        }
    }
    cout << n << " " << ans.size() << endl;
    for(auto &x:ans){
        cout << x << endl;
    }
}