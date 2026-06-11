#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(int)(n); i++)

using namespace std;
using LL = long long;
const LL INF=1LL<<60;

class SegmentTree {
private:
    int st_siz;
    vector<LL> ST_min, ST_max;

public:
    SegmentTree(int siz) {
        st_siz = 1;
        while(st_siz < siz) st_siz *= 2;
        ST_min = vector<LL>(2 * st_siz - 1, INF);
        ST_max = vector<LL>(2 * st_siz - 1, -INF);
    }

    int get_size() {
    	return st_siz;
    }

    void min_init(LL x) {
    	for(int i = 0; i < 2 * st_siz - 1; i++) ST_min[i] = x;
    }

	void max_init(LL x) {
		for(int i = 0; i < 2 * st_siz - 1; i++) ST_max[i] = x;
	}

    void min_update(int i, LL x) {
        i += st_siz - 1;
        ST_min[i] = x;
        while(i > 0) {
            i = (i - 1) / 2;
            ST_min[i] = min(ST_min[i * 2 + 1], ST_min[i * 2 + 2]);
        }
    }

    void max_update(int i, LL x) {
        i += st_siz - 1;
        ST_max[i] = x;
        while(i > 0) {
            i = (i - 1) / 2;
            ST_max[i] = max(ST_max[i * 2 + 1], ST_max[i * 2 + 2]);
        }
    }

    LL RmQ(int a, int b, int k, int l, int r, LL M = INF) {
        if (r <= a || b <= l) return M;
        if (a <= l && r <= b) return ST_min[k];
        else {
            LL m1 = RmQ(a, b, 2 * k + 1, l, (l + r) / 2, M);
            LL m2 = RmQ(a, b, 2 * k + 2, (l + r) / 2, r, M);
            return min(m1, m2);
        }
    }

    LL RMQ(int a, int b, int k, int l, int r, LL M = 0) {
        if (r <= a || b <= l) return M;
        if (a <= l && r <= b) return ST_max[k];
        else {
            LL M1 = RMQ(a, b, 2 * k + 1, l, (l + r) / 2, M);
            LL M2 = RMQ(a, b, 2 * k + 2, (l + r) / 2, r, M);
            return max(M1, M2);
        }
    }
};

int main(){
	int N;
	cin >> N;
	vector<int> h(N);
	rep(i,N) cin >> h[i];
	vector<LL> a(N);
	rep(i,N) cin >> a[i];
	vector<LL> dp(N);
	SegmentTree st(N);
	st.max_init(0);
	rep(i,N){
		int height=h[i]-1;
		dp[height]=st.RMQ(0,height,0,0,st.get_size())+a[i];
		st.max_update(height,dp[height]);
	}
	LL ans=0;
	rep(i,N) ans=max(ans,dp[i]);
	cout << ans << endl;

	return 0;
}