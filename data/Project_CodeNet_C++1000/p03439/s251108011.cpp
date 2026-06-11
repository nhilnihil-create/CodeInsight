#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,n) for(long long i=0;i<n;++i)
#define REPP(i,m,n) for(long long i=m;i<n;++i)
#define rep(i,n) for(long long i = n-1;i>=0;--i)
#define repp(i,n,m) for(long long i = n-1; i >= m; --i)
#define ALL(N) (N.begin(),N.end())
#define de cout << "line : " << __LINE__ << " debug" << endl;
#define pb push_back
#define pq priority_queue
#define Dcout(N) cout << setprecision(20) << N << endl
constexpr ll INF = 2147483647;
constexpr long long INFF = 9223372036854775807;

signed main() {
    cin.tie(0);
	ios::sync_with_stdio(false);
    int N;cin >> N;
    cout << 0 << endl;
    string S;
    cin >> S;
    string A;
    if(S == "Vacant") return 0;
    else A = S;
    int left = 0,right = N-1;
	int P = 20;
    while(P--){
        int mid = left + abs(right - left)/2;
        cout << mid << endl;
        cin >> S;
        if(S == "Vacant") return 0;
        else if(S == A && mid % 2 == 0) left = mid+1;
        else if(S != A && mid % 2 == 1) left = mid+1;
        else right = mid-1;
    }
}