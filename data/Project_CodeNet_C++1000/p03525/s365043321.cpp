#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr int Inf = 1000000000;
constexpr ll INF= 1e18;
constexpr ll MOD = 1000000007;
const double PI = 3.1415926535897;
typedef pair<ll,ll> P;

int N;
int ret = 0;
vector<int> vec(13);
vector<bool> T(25);

void def(int a) {
    if(a == 12) {
        int cnt = 0;
        int ret2 = Inf;
        for(int i = 1;i < 25;i++) {
            if(T.at(i) == true) {
                ret2 = min(ret2,i - cnt);
                cnt = i;
            }
        }
        ret = max(ret,ret2);
    }
    else {
        if(vec.at(a) == 2) {
            T.at(a) = true;
            T.at(24 - a) = true;
            def(a + 1);
        }
        else if(vec.at(a) == 1) {
            T.at(a) = true;
            def(a + 1);
            T.at(a) = false;
            T.at(24 - a) = true;
            def(a + 1);
            T.at(24 - a) = false;
        }
        else {
            def(a + 1);
        }
    }
    return;
}
int main() {
    cin >> N;
    vec.at(0) = 1;
    for(int i = 0;i < N;i++) {
        int A;
        cin >> A;
        vec.at(A)++;
    }
    bool cnt = true;
    for(int i = 1;i < 12;i++) {
        if(vec.at(i) >= 3) {
            cnt = false;
        }
    }
    if(vec.at(0) >= 2 || vec.at(12) >= 2) {
        cnt = false;
    }
    if(cnt == false) {
        cout << 0 << endl;
    }
    else {
        T.at(0) = true;
        T.at(24) = true;
        if(vec.at(12) != 0) {
            T.at(12) = true;
        }
        def(1);
        cout << ret << endl;
    }
}