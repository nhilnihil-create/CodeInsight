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

int min_diff(int i, multiset<int>st, multiset<int> ans){
    if(i==13){
        ans.insert(24);
        int pre=0,minimum=24;
        for(auto a: ans){
            minimum=min(minimum, a-pre);
            pre=a;
        }
        return minimum;
    }

    if(st.count(i)==1){
        auto s1=ans, s2=ans;
        s1.insert(i), s2.insert(24-i);
        return max(min_diff(i+1,st,s1), min_diff(i+1,st,s2));
    }else if(st.count(i)==2){
        ans.insert(i), ans.insert(24-i);
        return min_diff(i+1, st,ans);
    }else if(st.count(i)==0){
        return min_diff(i+1,st, ans);
    }else{
        return 0;
    }
}
int main() {
    int N; cin >> N;
    vector<int> D(N);
    multiset<int> ms, ans;
    rep(i,N){
        cin >> D[i];
        ms.insert(D[i]);
    }

    cout << min_diff(0, ms, ans) << endl;
    return 0;
}