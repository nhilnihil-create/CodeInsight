#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> l_l;
typedef pair<int, int> i_i;
template<class T>
inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return true;
    }
    return false;
}

template<class T>
inline bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return true;
    }
    return false;
}

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
//const ll mod = 1000000007;
string S;

int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> S;
    for(int i = 1; i < S.size(); i++) {
        if(S[i-1] == 'A' && S[i] == 'A') {
            cout << "NO" << endl;
            return 0;
        }
    }
    int index = 0;
    if(S[index] == 'A') index++;
    if(S.size() == index || S[index] != 'K') {
        cout << "NO" << endl;
        return 0;
    }
    index++;
    if(S.size() == index || S[index] != 'I') {
        cout << "NO" << endl;
        return 0;
    }
    index++;
    if(S.size() == index || S[index] != 'H') {
        cout << "NO" << endl;
        return 0;
    }
    index++;
    if(index < S.size() && S[index] == 'A') index++;
    if(S.size() == index || S[index] != 'B') {
        cout << "NO" << endl;
        return 0;
    }
    index++;
    if(index < S.size() && S[index] == 'A') index++;
    if(S.size() == index || S[index] != 'R') {
        cout << "NO" << endl;
        return 0;
    }
    index++;
    if(index < S.size() && S[index] == 'A') index++;
    if(index != S.size()) {
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl;
    return 0;
}
