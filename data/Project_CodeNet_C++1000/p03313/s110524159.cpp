#include "bits/stdc++.h"
using namespace std;
#define ff first
#define ss second
typedef pair<pair<int,int>,pair<int,int>> P;
vector<P> v;
P mx(P m, P x){
    if(m.ff == x.ff)
        return {x.ff, max(m.ss, x.ss)};
    if(m.ff < x.ff)
        return {x.ff, max(m.ff, x.ss)};
    else
        return {m.ff, max(m.ss, x.ff)};
}
signed main(){
    int n, x;
    cin >> n;
    int N = 1 << n;
    for(int i = 0; i < N; i++){
        cin >> x;
        v.push_back({{x,i},{0,-1}});
    }
    for(int j = 1; j < N; j <<= 1)
        for(int i = 0; i < N; i++)
            v[i|j] = mx(v[i|j], v[i]);
    int m = 0;
    for(int i = 0; i < N; i++){
        m = max(m, v[i].ff.ff+v[i].ss.ff);
        if(i)cout << m << endl;
    }
}
