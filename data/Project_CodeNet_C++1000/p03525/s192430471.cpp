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
const ll INF = (1ll<<60);
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

int a[]={1,1,2,2,3,3,4,4,5,5,6,6,7,7,8,8,9,9,10,10,11,11,12};
int main() {
    int N; cin >> N;
    vector<int> D(N);
    rep(i,N){
        cin >> D[i];
    }

    if(N>=24){
        cout << 0 << endl;
        return 0;
    }
    
    if(N==23){
        sort(D.begin(), D.end());
        for(int i=0; i<23; i++){
            if(a[i]!=D[i]){
                cout << 0 << endl;
                return 0;
            }
        }
        cout << 1 << endl;
        return 0;
    }

    int ans=0;
    multiset<int> st;
    for(ll i=0; i<(1LL<<N); i++){
        ll b=i;
        st.insert(24);
        for(int j=0; j<N; j++){
            if(b&1){
                st.insert(D[j]);
            }else{
                st.insert(24-D[j]);
            }
            b=b>>1;
        }
        int pre=0;
        int minimum=24;
        for(auto a: st){
            minimum=min(minimum, a-pre);
            pre=a;
        }
        ans=max(minimum,ans);
        st.clear();
    }

    cout << ans << endl;
    return 0;
}