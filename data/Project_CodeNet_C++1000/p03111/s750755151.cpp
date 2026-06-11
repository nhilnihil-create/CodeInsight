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

int n,a,b,c;
vector<int> l;
int ans = INF;

void dfs(vector<int> v, int cnt){
    if(cnt == n){
        int cnt1 = 0,cnt2 = 0,cnt3 = 0;
        int len1 = 0,len2 = 0,len3 = 0;
        rep(i,n){
            if(v[i] == 1){
                cnt1++;
                len1 += l[i];
            }
            if(v[i] == 2){
                cnt2++;
                len2 += l[i];
            }
            if(v[i] == 3){
                cnt3++;
                len3 += l[i];
            }
        }
        if(len1 == 0 || len2 == 0 || len3 == 0) return;
        int now = (cnt1-1)*10+(cnt2-1)*10+(cnt3-1)*10+abs(len1-a)+abs(len2-b)+abs(len3-c);
        ans = min(ans,now);
        return;
    }

    rep(i,4){
        v[cnt] = i;
        dfs(v,cnt+1);
    }

}

int main(){
    cin >> n >> a >> b >> c;
    l.resize(n);
    rep(i,n) cin >> l[i];
    vector<int> v(n);
    int cnt = 0;
    dfs(v,cnt);
    cout << ans << endl;
}

