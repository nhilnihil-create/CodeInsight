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
void readvec(vector<T> &a);
void readindex(vector<int> &a);

vec binaryrep(int x, int n){
    vec b(n);
    REP(i, n){
        b[i] = x % 2;
        x /= 2;
    }
    return b;
}

signed main(){

    int N; cin >> N;
    vec X(N), Y(N);
    REP(i, N) cin >> X[i] >> Y[i];
    int p = (llabs(X[0]) + llabs(Y[0])) % 2;
    REP(i, N) if((llabs(X[i]) + llabs(Y[i])) % 2 != p){
        cout << -1;
        return 0;
    }

    int m = 31;
    cout << m + 1 - p << endl;
    if(p == 0) cout << 1 << " ";
    REP(i, m) cout << (1 << i) << " ";
    cout << endl;

    REP(i, N){
        string ans = "";
        if(p == 0){
            ans += 'R';
            X[i]--;
        }
        int u = X[i] + Y[i];
        int v = X[i] - Y[i];
        int mm = (1 << m) - 1;
        u = (u + mm) / 2;
        v = (v + mm) / 2;
        vec b_u = binaryrep(u, m);
        vec b_v = binaryrep(v, m);
        REP(i, m){
            if(b_u[i] == 0 && b_v[i] == 0) ans += 'L';
            else if(b_u[i] == 1 && b_v[i] == 0) ans += 'U';
            else if(b_u[i] == 0 && b_v[i] == 1) ans += 'D';
            else if(b_u[i] == 1 && b_v[i] == 1) ans += 'R';
        }
        cout << ans << endl;
    } 

    
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