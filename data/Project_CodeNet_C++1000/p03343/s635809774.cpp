#include <stdio.h>
#include <string>
#include <cstring>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <list>
#include <iterator>
#include <assert.h>
#pragma warning(disable:4996) 
 
typedef long long ll;
#define MIN(a, b) ((a)>(b)? (b): (a))
#define MAX(a, b) ((a)<(b)? (b): (a))
#define LINF 9223300000000000000
#define INF 2140000000
const long long MOD = 1000000007;
//const long long MOD = 998244353;

using namespace std;



void solve()
{
    int n,K,Q;
    scanf("%d%d%d", &n, &K, &Q);
    vector<int> a(n);
    vector<pair<int, int> > z;
    int i,j;
    map<int, int> cnt;
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        z.push_back(make_pair(a[i], i));
        cnt[a[i]]++;
    }
    sort(z.begin(), z.end());

    ll ans = LINF;
    auto it = cnt.begin();
    for(; it!=cnt.end(); ++it) {
        int tmp0=it->first;
        vector<int> save;
        int cnt = 0;
        for (i = 0; i < n; i++) {
            int val = z[i].first;
            int id = z[i].second;
            if (val < tmp0) {
                save.push_back(id);
            }
            else {
                break;
            }
        }
        save.push_back(-1);
        save.push_back(n);
        sort(save.begin(), save.end());
        int siz = (int)save.size();

        ll ans0 = -INF;
        vector<int> num(siz);
        int cnt0 = 0;
        for (; i < n; i++) {
            int val = z[i].first;
            int id = z[i].second;
            int k=lower_bound(save.begin(), save.end(), id) - save.begin();
            k--;
            int tmp=save[k+1] - save[k] - 1;
            if (tmp - num[k] >= K) {
                cnt0++;
                ans0 = MAX(ans0, val);
                num[k]++;
                if (cnt0 == Q) {
                    break;
                }
            }
        }
        if (i == n) {
            continue;
        }
        ans=MIN(ans,ans0 - tmp0);
    }
    printf("%lld\n", ans);


    return;
}

int main(int argc, char* argv[])
{
#if 1
    solve();
#else
    int T; scanf("%d", &T);
    while(T--) {
        solve();
    }
#endif
    return 0;
}
