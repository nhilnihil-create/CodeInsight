#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i = 0; i < (n); ++i)

typedef long long ll;
typedef pair<int, int> P;

const int MAX = 1e5 + 5;
const int INF = 1001001001;
const int MOD = 1e9 + 7;

int c(int i) {
    cout << i << endl;
    string s;
    cin >> s;
    if (s == "Male") return -1;
    if (s == "Female") return 1;
    exit(0);
}

int main(){
    int N;
    string s;
    
    cin >> N;
    vector<int> v(N, 0);
    v[0] = c(0);

    int l = 0, r = N;
    while (r - l > 1) {
        int mid = (l + r) / 2;
        v[mid] = c(mid);

        if ((mid - l) % 2 == 0) {
            if (v[l] == v[mid]) {
                l = mid;
            } else {
                r = mid;
            }
        } else {
            if (v[l] == v[mid]) {
                r = mid;
            } else {
                l = mid;
            }
        }
    }
}