#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <iomanip>
#include <map>
#include <set>
#include <cmath>
#include <cstdio>
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define FOR(i,m,n) for(int (i)=(m);(i)<(n);(i)++)
#define All(v) (v).begin(),(v).end()
typedef long long ll;

int main(){
    int N;cin >> N;
    vector<int> am(N),bm(N);
    rep(i,N)cin >> am[i];
    rep(i,N)cin >> bm[i];
    ll res = 0;
    for(int k=29;k>=0;k--){
        //vector<int> am(N),bm(N);
        ll T =(1<<k);
        rep(i,N){
            am[i]=am[i]%(2*T);
            bm[i]=bm[i]%(2*T);
        }
        sort(All(bm));

        ll is_one = 0;
        rep(i,N){
            int add = 0;
            if(am[i]<=T){
                add += lower_bound(All(bm),(2*T)-am[i])-lower_bound(All(bm),T-am[i]);
            }else{
                //add += lower_bound(All(bm),(1<<(k+1)))-bm.begin();
                //add -= lower_bound(All(bm),(3*(1<<k))-a[i])-lower_bound(All(bm),(1<<(k+1))-a[i]);
                add+=lower_bound(All(bm),(2*T)-am[i])-bm.begin();
                add+=lower_bound(All(bm),(2*T))-lower_bound(All(bm),(3*T)-am[i]);
            }
            is_one+=add;
        }
        if(is_one&1)res+=T;
    }
    cout << res << endl;
    return 0;
}