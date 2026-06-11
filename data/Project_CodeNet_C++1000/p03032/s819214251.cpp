#include <bits/stdc++.h>
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

int n, k;

int main() {
    cin >> n >> k;
    vector<long long> V(n, 0);
    for(int i = 0; i < n; ++i) cin >> V.at(i);

    int limit = min(n, k);
    long long vans = 0;
    for(int left = 0; left <= limit; ++left) {
        vector<long long> lvec;
        for(int i = 0; i < left; ++i) lvec.emplace_back(V.at(i));
        for(int right = 0; right <= limit-left; ++right) {
            vector<long long> ansvec;
            ansvec = lvec;
            for(int j = 0; j < right; ++j) ansvec.emplace_back(V.at(n-1-j));
            int dust = k-left-right;
            long long sum = 0;
            sort(ansvec.begin(), ansvec.end());
            int anslen = ansvec.size();
            for(int l = 0; l < min(anslen, dust); ++l) {
                if(ansvec.at(l) < 0) ansvec.at(l) = 0;
                else break;
            }

            for(int l = 0; l < ansvec.size(); ++l) sum += ansvec.at(l);
            chmax(vans, sum);
        }
    }
    cout << vans << endl;
}