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
    vector<int> a(N),b(N);
    rep(i,N)cin >> a[i];
    rep(i,N)cin >> b[i];
    ll res = 0;
    for(int k=0;k<30;k++){
        vector<int> am(N),bm(N);
        rep(i,N){
            am[i]=a[i]%(1<<(k+1));
            bm[i]=b[i]%(1<<(k+1));
        }
        sort(All(bm));

        ll is_one = 0;
        rep(i,N){
            int add = 0;
            if(am[i]<=(1<<k)){
                add += lower_bound(All(bm),(1<<(k+1))-am[i])-lower_bound(All(bm),(1<<k)-am[i]);
            }else{
                //add += lower_bound(All(bm),(1<<(k+1)))-bm.begin();
                //add -= lower_bound(All(bm),(3*(1<<k))-a[i])-lower_bound(All(bm),(1<<(k+1))-a[i]);
                add+=lower_bound(All(bm),(1<<(k+1))-am[i])-bm.begin();
                add+=lower_bound(All(bm),(1<<(k+1)))-lower_bound(All(bm),(3*(1<<k))-am[i]);
            }
            is_one+=add;
        }
        if(is_one&1)res+=(1<<k);
    }
    cout << res << endl;
    return 0;
}