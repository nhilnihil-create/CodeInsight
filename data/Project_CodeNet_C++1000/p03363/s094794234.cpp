#include <bits/stdc++.h>
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

int n;
vector<long long> A(200200, 0);
vector<long long> sum(200200, 0);

int main() {
    cin >> n;
    for(int i = 0; i < n; ++i) cin >> A.at(i);

    sum.at(0) = A.at(0);
    for(int i = 1; i < n; ++i) {
        sum.at(i) += sum.at(i-1) + A.at(i);
    }

    long long cnt = 0;
    map<long long, long long> mp;
    set<long long> st;
    for(int i = 0; i < n; ++i) {
        if(sum.at(i) == 0) cnt++;
        mp[sum.at(i)]++;
        st.insert(sum.at(i));
    }

    for(auto itr = st.begin(); itr != st.end(); ++itr) {
        long long mcnt = mp[*itr];
        cnt += (mcnt*(mcnt-1)) / 2;
    }

    cout << cnt << endl;
}