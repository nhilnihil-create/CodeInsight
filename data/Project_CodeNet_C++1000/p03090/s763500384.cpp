#include<bits/stdc++.h>
#define int long long
using namespace std;
const int INF = 1e14;
const int ZERO = 0;
const int MOD = 1000000007;
const double PI = 3.1415926535897;
typedef pair<int,int> P;

signed main() {
    int N;
    cin >> N;
    if(N % 2 == 0) {
        cout << (N * (N - 1) - N) / 2 << endl;
        for(int i = 1;i <= N;i++) {
            for(int j = 1;j <= N;j++) {
                if(i < j && j != N - (i - 1)) {
                    cout << i << " " << j << endl;
                }
            }
        }
    }
    else {
        cout << (N * (N - 1) - (N - 1)) / 2 << endl;
        for(int i = 1;i <= N;i++) {
            for(int j = 1;j <= N;j++) {
                if(i < j && j != N - i) {
                    cout << i << " " << j << endl;
                }
            }
        }
    }                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                       
}