#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<bitset>
#include<set>
#include<map>
#include<stack>
#include<queue>
#include<deque>
#include<list>
#include<iomanip>
#include<cmath>
#include<cstring>
#include<functional>
#include<cstdio>
#include<cstdlib>
using namespace std;

#define repr(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
#define rep(i, n) repr(i, 0, n)
#define INF 2e9
#define MOD 1000000007
//#define MOD 998244353
#define LINF (long long)4e18
#define jck 3.141592

const double EPS = 1e-10;

using ll = long long;
using Pi = pair<int,int>;
using Pl = pair<ll,ll>;



int main(){
    int N,K,Q; cin >> N >> K >> Q;
    vector<int> a(N);
    rep(i,N) cin >> a[i];
    int ans = INF;
    rep(i,N){
        vector<int> v;
        vector<vector<int>> v2(N);
        int now = 0;
        rep(j,N){
            if(a[j] < a[i]){
                rep(k,v.size()){
                    v2[now].push_back(v[k]);
                }
                now++;
                v.clear();
            }
            else{
                v.push_back(a[j]);
            }
        }
        rep(j,v.size()){
            v2[now].push_back(v[j]);
        }
        vector<int> v3;
        rep(j,N){
            sort(v2[j].begin(),v2[j].end());
            rep(k,max(0,(int)v2[j].size()-K+1)){
                v3.push_back(v2[j][k]);
            }
        }
        sort(v3.begin(),v3.end());
        if(v3.size() < Q) continue;
        int Min = INF;
        int Max = 0;
        rep(j,Q){
            Min = min(Min,v3[j]);
            Max = max(Max,v3[j]);
        }
        ans = min(ans,Max-Min);
    }
    cout << ans << endl;
}
