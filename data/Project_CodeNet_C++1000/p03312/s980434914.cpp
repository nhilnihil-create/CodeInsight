#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef set<int> si;
typedef pair<int,int> pii;
#define rep(i,a,b) for(int i=(a); i<(b); ++i)
#define per(i,a,b) for(int i=(b)-1; i>=(a); --i)
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define F first
#define S second
const int INF = 987654321;
const ll MOD = 1e9+7;

int n; 
vl a;
vl psum;

ll diffL(int i, int a) {
    return abs(psum[i-1]-2*psum[a-1]);
}

ll diffR(int i, int b) {
    return abs(psum[n]-2*psum[b-1]+psum[i-1]);
}

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	//freopen("in.txt", "r", stdin);
    cin >> n;
    a.resize(n+1);
    psum.resize(n+1);
    rep(i,1,n+1) {
        cin >> a[i];
    }
    rep(i,1,n+1) {
        psum[i] = psum[i-1] + a[i];
    }
    ll ret = 1e18;
    int a = 2;
    int b = 4;
    rep(i,3,n) {
        if(b==i) b++;
        while(a+1 < i && diffL(i,a+1) < diffL(i,a)) {
            a++;
        }
        while(b+1 <= n && diffR(i, b+1) < diffR(i,b)) {
            b++;
        }
        //cout << a << ", " << i << ", " << b << endl;
        vl cand(4);
        cand[0] = psum[a-1];
        cand[1] = psum[i-1] - psum[a-1];
        cand[2] = psum[n] - psum[b-1];
        cand[3] = psum[b-1] - psum[i-1];
        sort(all(cand));
        ret = min(ret, cand[3]-cand[0]);
    }
    cout << ret << endl;
	return 0;
}
