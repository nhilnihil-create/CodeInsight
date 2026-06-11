#include <bits/stdc++.h>
#define FOR(i, begin, end) for(int i=(begin);i<(end);i++)
#define REP(i, n) FOR(i,0,n)
#define IFOR(i, begin, end) for(int i=(end)-1;i>=(begin);i--)
#define IREP(i, n) IFOR(i,0,n)
#define SORT(a) sort(a.begin(), a.end())
#define REVERSE(a) reverse(a.begin(), a.end())
#define int long long
#define INF 1000000000000000000
using namespace std;

typedef vector<int> vec;
typedef vector<vec> mat;
typedef pair<int, int> Pii;

template<typename T>
void readvec(vector<T> &a);
void readindex(vector<int> &a);



signed main(){

    int N, X; cin >> N >> X;
    vec x(N); readvec(x);

    vec sumx(N + 1);
    sumx[0] = 0;
    REP(i, N) sumx[i + 1] = sumx[i] + x[i];

    int ans = INF;
    IFOR(k, 1, N + 1){
        int tmp = (N + k) * X;
        int n = N / k + min(1LL, N % k);
        tmp += (sumx[N] - sumx[N - k]) * 5;
        FOR(i, 2, n + 1){
            int y = sumx[N - k * (i - 1)] - sumx[max(0LL, N - k * i)];
            if((double)(ans - tmp) / (double)(y) < 2 * i + 1){
                tmp = INF;
                break;
            }
            tmp += y * (2 * i + 1);
        }
        ans = min(tmp, ans);
    }

    cout << ans;
    
    return 0;
}


template<typename T>
void readvec(vector<T> &a){
    REP(i, a.size()){
        cin >> a[i];
    }
}
void readindex(vector<int> &a){
    REP(i, a.size()){
        cin >> a[i];
        a[i]--;
    }
}