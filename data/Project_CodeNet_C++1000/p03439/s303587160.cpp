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

using namespace std;

#define INF (1ll<<60)
#define INFint (1<<30)
#define MOD 1000000007
#define BOUND 27182818284

typedef long long ll;
typedef long long int lli;
typedef pair<ll, ll> P;

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

int findGCD(int arr[], int n) {
    int result = arr[0];
    for (int i = 1; i < n; i++)
        result = gcd(arr[i], result);
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

int main() {
    int N; cin >> N;
    string left_s, right_s;

    cout << 0 << endl;
    cin >> left_s;
    if(left_s=="Vacant")
        return 0;

    cout << N-1 << endl;
    cin >> right_s;
    if(right_s=="Vacant")
        return 0;

    int left=0,right=N-1;
    while(true){
        int mid=(left+right)/2;
        string m_string;
        cout << mid << endl;
        cin >> m_string;

        if(m_string=="Vacant")
            return 0;

        bool odd = ((mid - left + 1) % 2==1);
        bool same = (m_string == left_s);
        if(odd ^ same) {
            right = mid;
            right_s = m_string;
        }
        odd = ((right - mid + 1) % 2==1);
        same = (m_string == right_s);
        if(odd ^ same) {
            left = mid;
            left_s = m_string;
        }
    }
    return 0;
}