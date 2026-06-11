#include <bits/stdc++.h>
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

const long long INF = 1e18;
int n;

int main() {
    cin >> n;
    vector< vector<int> > F(n, vector<int>(10, 0));
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < 10; ++j) {
            cin >> F.at(i).at(j);
        }
    }

    vector< vector<long long> > P(n, vector<long long>(11, 0));
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < 11; ++j) {
            cin >> P.at(i).at(j);
        }
    }

    long long mans = -INF;
    for(int bit = 1; bit < (1<<10); ++bit) {
        vector<int> flg(10, 0);
        for(int i = 0; i < 10; ++i) {
            if(bit & (1<<i)) flg.at(i) = 1;
        }

        long long sum = 0;
        for(int i = 0; i < n; ++i) {
            int icnt = 0;
            for(int j = 0; j < 10; ++j) {
                if(flg.at(j) == F.at(i).at(j)) {
                    if(flg.at(j) == 1) icnt++;
                }
            }
            sum += P.at(i).at(icnt);
        }
        chmax(mans, sum);
    }

    cout << mans << endl;
}