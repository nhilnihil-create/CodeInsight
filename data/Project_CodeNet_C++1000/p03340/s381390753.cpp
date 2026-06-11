#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> P;
int INF = 1e16+7;
int mod = 998244353;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
signed main() {
    int N;
    cin >> N;
    vector<int>A(N);
    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }
    vector<int>cnt(N);
    int l = 0,r = 0;
    int sum = 0,OR = 0;
    int ans = 0;
    while(r < N) {
        OR ^= A[r];
        sum += A[r];
        if(OR == sum) {
            ans+=r-l+1;
        }
        else {
            while(OR != sum) {
                OR ^= A[l];
                sum -= A[l];
                l++;
                if(OR == sum) {
                    ans+=r-l+1;
                }
            }
        }
        r++;
    }
    cout << ans << endl;
}
