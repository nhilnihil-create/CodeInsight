#include <bits/stdc++.h>
#define FOR(i, begin, end) for(int i=(begin);i<(end);i++)
#define REP(i, n) FOR(i,0,n)
#define IFOR(i, begin, end) for(int i=(end)-1;i>=(begin);i--)
#define IREP(i, n) IFOR(i,0,n)
#define SORT(a) sort(a.begin(), a.end())
#define REVERSE(a) reverse(a.begin(), a.end())
#define Lower_bound(v, x) distance(v.begin(), lower_bound(v.begin(), v.end(), x))
#define Upper_bound(v, x) distance(v.begin(), upper_bound(v.begin(), v.end(), x))
#define int long long
#define INF 1000000000000000000
using namespace std;

typedef vector<int> vec;
typedef vector<vec> mat;
typedef pair<int, int> Pii;

template<typename T>
void readv(vector<T> &a){ REP(i, a.size()) cin >> a[i]; }
void readi(vector<int> &a){ REP(i, a.size()){cin >> a[i]; a[i]--;} }



signed main(){

    int N; cin >> N;
    int k = -1;
    REP(i, N + 10) if(i * (i - 1) / 2 == N) k = i;

    if(k == - 1){
        cout << "No";
    }else{
        cout << "Yes" << endl;
        cout << k << endl;
        mat ans(k, vec(0));
        int n = 1;
        REP(i, k){
            FOR(j, i + 1, k){
                ans[i].push_back(n);
                ans[j].push_back(n);
                n++;
            }
        }
        REP(i, k){
            cout << ans[i].size() << " ";
            REP(j, ans[i].size()) cout << ans[i][j] << " ";
            cout << endl;
        }
    }
    
    return 0;
}