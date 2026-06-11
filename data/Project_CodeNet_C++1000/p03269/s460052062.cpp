#include<bits/stdc++.h>
#define ALL(c) (c).begin(),(c).end()
#define EACH(i,c) for(auto i=(c).begin();i!=(c).end();++i)
using namespace std;
#define int long long


void solve(long long L) {
    int t = 1, k = 0;
    while (t <= L) {
        t *= 2;
        k++;
    }
    int N = k;
    vector<tuple<int, int, int>> v;
    for (int i = 0; i < k - 1; ++i) {
        v.push_back(make_tuple(i + 1, i + 2, 0));
        v.push_back(make_tuple(i + 1, i + 2, 1LL << i));
    }
    for (int i = 0; i < k - 1; ++i) {
        if (L & (1LL << i)) {
            int p = (1LL << (i + 1)) - 1;
            v.push_back(make_tuple(i + 1, N, L & ~p));
        }
    }
    cout << N << " " << v.size() << endl;
    for (auto e: v) {
        cout << get<0>(e) << " " << get<1>(e) << " " << get<2>(e) << endl;
    }
}

signed main(){
	ios::sync_with_stdio(false);
    long long L;
    scanf("%lld",&L);
    solve(L);
    return 0;
}