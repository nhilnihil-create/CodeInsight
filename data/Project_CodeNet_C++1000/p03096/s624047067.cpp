#include <cstdio>
#include <iostream>
#include <iomanip>
#include <functional>
#include <algorithm>
#include <string>
#include <vector>
#include <limits>
#include <numeric>
#include <queue>
#include <cmath>
#include <set>
#include <map>
#include <stack>

using namespace std;

#define INFint (1<<30)
#define BOUND 27182818284
#define MAT 2

typedef long long ll;
typedef long long int lli;
typedef pair<ll, ll> P;

ll MOD = 1000000007;
const ll INF = (1ll << 60);
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define repi(i, a, b) for(int i=int(a);i<int(b);++i)

template<class T>
bool umax(T &a, const T &b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

template<class T>
bool umin(T &a, const T &b) {
    if (b < a) {
        a = b;
        return true;
    }
    return false;
}

// gcd
template<typename T>
T gcd(T a, T b) {
    if (a == 0)
        return b;
    return gcd(b % a, a);
}

int findGCD(vector<int> arr) {
    int result = arr[0];
    for (auto a: arr) {
        result = gcd(a, result);
    }
    return result;
}

template<typename T>
T lcm(T m, T n) {
    // 引数に0がある場合は0を返す
    if ((0 == m) || (0 == n))
        return 0;
    return ((m / gcd(m, n)) * n); // lcm = m * n / gcd(m,n)
}

template<typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val) {
    fill((T *) array, (T *) (array + N), val);
}


int dx[5] = {1, 0, -1, 0};
int dy[5] = {0, 1, 0, -1};

// v.front() = -BOUND;
// v.back() = BOUND;

//struct edge{
//    int cost, to;
//
//    edge(int in_cost, int in_to){
//        cost=in_cost;
//        to=in_to;
//    }
//    bool operator<(const edge &a) const
//    {
//        return cost > a.cost;
//    }
//};




vector<ll>sum(200010,0);
vector<ll>pre(200010,0);
int main() {
    int N; cin >> N;
    vector<int> C(N+1);

    rep(i,N){
        cin >> C[i+1];
    }

    sum[0]=1LL;
    for(int i=1; i<=N; i++){
        if(C[i]==C[i-1]){
            sum[i]=sum[i-1];
        }else if(pre[C[i]]==0){
            sum[i]=sum[i-1];
        }else{
            sum[i]=sum[i-1]+sum[pre[C[i]]];
        }
        sum[i]%=MOD;
        pre[C[i]]=i;
    }

    cout << sum[N] << endl;
    return 0;
}