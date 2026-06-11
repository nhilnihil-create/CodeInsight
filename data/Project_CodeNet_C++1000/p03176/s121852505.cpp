#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define pb push_back

#define int int64_t
#define ld long double

const int MOD = 1e9+7;
const int N = 1e6+5;

typedef int dat;
 
struct SegmentTree
{
    int N;
    vector<dat> st;
    
    dat merge(dat a, dat b)
    {
        dat res = max(a,b);
        return res;
    }
 
    dat query(int node, int l, int r, int i, int j)
    {
        if(l >= i && r <= j)
            return st[node];
        int m = (l+r)/2;
        if(j <= m)
            return query(2*node, l, m, i, j);
        else if(i >= m+1)
            return query(2*node+1, m+1, r, i, j);
        else
            return merge(query(2*node, l, m, i, j), query(2*node+1, m+1, r, i, j));
    }
 
    //modify arguments and handle point update as per question
    void update(int node, int l, int r, int pos, int val)
    {
        if(l == r)
        {
 			st[node]=max(st[node], val);
            return;
        }
        int m = (l+r)/2;
        if(pos <= m)
            update(2*node, l, m, pos, val);
        else if(pos >= m+1)
            update(2*node+1, m+1, r, pos, val);
        st[node] = merge(st[2*node], st[2*node+1]);
    }
 
    SegmentTree(int tree_size)
    {
        N=tree_size;
        st.resize(4*N+5);
    }
 
    dat query(int i, int j)
    {
        dat res = query(1, 0, N-1, i, j);
        return res;
    }
    
    void update(int pos, int val)
    {
        update(1, 0, N-1, pos, val);
    }
};

int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin>>n;
	int h[n];
	int a[n];
	for(int i=0;i<n;i++) {
		cin>>h[i];
	}	
	for(int i=0;i<n;i++) {
		cin>>a[i];
	}	

	SegmentTree st = SegmentTree(n+1);

	int dp[n+1];
	memset(dp, 0, sizeof(dp));
	dp[0]=0;
	int ans = 0;
	for(int i=0;i<n;i++) {
		int mx = st.query(0, h[i]-1);
		st.update(h[i], mx+a[i]);
		ans = max(ans, st.query(h[i], h[i]));
	}

	cout<<ans;

	return 0;
}