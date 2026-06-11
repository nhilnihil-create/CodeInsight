#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> P;
int INF = 1e9+7;
int mod = 100000;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
signed main() {
    vector<bool>cnt(55560,true);
    cnt[0] = false;cnt[1] = false;
    for(int i = 2; i <= 55555; i++) {
        if(!cnt[i]) {
            continue;
        }
        for(int j = i*2; j <= 55555; j+=i) {
            cnt[j] = false;
        }
    }
    int N;
    cin >> N;
    while(N) {
        for(int i = 1; i <= 55555; i+=5) {
            if(cnt[i]) {
                if(i != 11) {
                    cout << " ";
                }
                cout << i;
                N--;
                if(N == 0) {
                    break;
                }
            }
        }
    }
    cout << endl;
}
