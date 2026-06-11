#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr int Inf = 1000000000;
constexpr ll INF= 9 * 1e18;
constexpr ll MOD = 1000000007;
const double PI = 3.1415926535897;
typedef pair<int,int> P;

template<typename T>
T Pow(T a,T b) {
    T ret = 1;
    for(int i = 0;i < b;i++) {
        ret *= a;
    }
    return ret;
}

int main() {
    int N;
    cin >> N;
    map<int,int> ma;
    for(int i = 0;i < N;i++) {
        int A;
        cin >> A;
        ma[A]++;
    }
    int M;
    cin >> M;
    bool ret = true;
    for(int i = 0;i < M;i++) {
        int A;
        cin >> A;
        if(ma[A] == 0) {
            ret = false;
        }
        else {
            ma[A]--;
        }
    }
    if(ret == true) {
        cout << "YES" << endl;
    }
    else {
        cout << "NO" << endl;
    }
}