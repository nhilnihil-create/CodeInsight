#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> P;
int INF = 1e9+7;
int mod = 1e9+7;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int mypow(int x,int n){
    if(n==0)
        return 1;
    if(n%2==1)
        return mypow(x,n-1)*x;
    int tmp=mypow(x,n/2);
    return tmp*tmp;
}
signed main() {
    int N;
    cin >> N;
    int ans = INF;
    for(int i = 0; i <= N; i++) {
        int cnt = N-i;
        int res = i;
        int sum = 0;
        while(res) {
            sum+=res%6;
            res/=6;
        }
        while(cnt) {
            sum+=cnt%9;
            cnt/=9;
        }
        ans = min(ans,sum);
    }
    cout << ans << endl;
}