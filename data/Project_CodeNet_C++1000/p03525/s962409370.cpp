#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> l_l;
typedef pair<int , int> i_i;
typedef vector<ll> vel;
typedef vector<int> vei;
typedef vector<char> vec;
typedef vector<bool> veb;
typedef vector<string> ves;
typedef vector<vector<ll>> ve_vel;
typedef vector<vector<int>> ve_vei;
typedef vector<vector<char>> ve_vec;
typedef vector<vector<bool>> ve_veb;
typedef vector<vector<string>> ve_ves;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep1(i,n) for(int i=1;i<(int)(n);i++)
#define rep2(i,n) for(int i=2;i<(int)(n);i++)
#define repk(i,k,n) for(int i=k;i<(int)(n);i++)
#define fs first
#define sc second
#define pub push_back
#define pob pop_back
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define maxel(a) *max_element(all(a))
#define minel(a) *min_element(all(a))
#define acc accumulate
#define EPS (1e-7)
//#define INF (1e9)
#define PI (acos(-1))
#define mod (1000000007)
typedef long long int64;
const int64 INF = 1LL << 58;
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);

    int N; cin >> N;
    vei cnt(13,0);
    cnt[0]++;
    rep(i,N) {
        int d; cin >> d;
        cnt[d]++;
    }
    rep(i,13) if(cnt[i] > 2) { cout << 0 << endl; return 0; }

    int ans = 0;


    for (int bit = 0; bit < (1<<13); ++bit) {
        vector<int> S;
        for (int i = 0; i < 13; ++i) {
            if(!cnt[i]) continue;
            else if(cnt[i] == 1) {
                if (bit & (1<<i)) S.pub(i);
                else S.pub(24 - i);
            }
            else {
                S.pub(i);
                S.pub(24 - i);
            }
        }

        int temp = 24;
        for (int i = 0; i < S.size(); i++) {
            for(int j = i+1; j < S.size(); j++) {
                int x = abs(S[i] - S[j]);
                temp = min(temp, min(24 - x, x));
            }
        }
        ans = max(ans, temp);
    }
    cout << ans << endl;
    return 0;
    
}