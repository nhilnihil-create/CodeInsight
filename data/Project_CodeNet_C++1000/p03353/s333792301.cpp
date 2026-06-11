# include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair <ll, ll> l_l;
typedef pair<int, int> i_i;

template<class T>
inline bool chmax(T &a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

template<class T>
inline bool chmin(T &a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}

# define EPS (1e-7)
# define INF (1e9)
# define PI (acos(-1))
//const ll mod = 1000000007;

string s;
int K;

int main() {
    cin >> s >> K;

    vector<string> substrings;
    for (int i = 0; i < s.length(); ++i) {
        for (int j = 1; j <= K; ++j) {
            substrings.push_back(s.substr(i, j));
        }
    }
    sort(substrings.begin(), substrings.end());

    int counter = 0;
    int idx = 0;
    string prev = " ";
    while (counter < K) {
        if (prev != substrings[idx]) {
            prev = substrings[idx];
            counter++;
        }
        idx++;
    }
    cout << substrings[idx-1] << endl;
    return 0;
}