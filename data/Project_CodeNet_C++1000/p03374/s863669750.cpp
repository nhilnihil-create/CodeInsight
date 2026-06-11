#include "iostream"
#include "vector"
#include "algorithm"
#include "map"
#define N_MAX 100005

using namespace std;

typedef long long llint;

llint N, C;
llint x[N_MAX];
int v[N_MAX];
llint A1[N_MAX];
llint A2[N_MAX];
llint B1[N_MAX];
llint B2[N_MAX];
llint g[N_MAX];


int main() {
    
    cin >> N >> C;

    for (int i = 0; i < N; i++) {
        cin >> x[i] >> v[i];
    }

    llint sum = 0;
    llint m1 = 0;
    llint m2 = 0;
    for (int i = 1; i <= N; i++) {
        sum += v[i - 1];
        m1 = max(m1, sum - x[i - 1]);
        m2 = max(m2, sum - 2 * x[i - 1]);
        A1[i] = m1;
        A2[i] = m2;
    }
    sum = 0;    
    m1 = 0;
    m2 = 0;
    for (int i = N - 1; i >= 0; i--) {
       sum += v[i];
       m1 = max(m1, sum - (C - x[i]));
       m2 = max(m2, sum - 2 * (C - x[i]));
       B1[i] = m1;
       B2[i] = m2; 
    }

    llint ans = 0;
    for (int i = 0; i <= N; i++) {
        ans = max(ans, max(A2[i] + B1[i], A1[i] + B2[i]));
    }

    cout << ans << endl;
}