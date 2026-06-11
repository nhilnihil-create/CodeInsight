#include <bits/stdc++.h>
#define int long long
typedef long long ll;
using namespace std;

const ll MAXN = 200000;
const ll INF = 1001001001;

ll N, ans=0, tmp=0;
vector<ll> A;

signed main(){
    cin >> N;
    char S1[N][N], S2[N][N];
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            cin >> S1[i][j];
        }
    }
    for(int i=0;i<N;i++) {
        for(int m=0;m<N;m++) {
            for(int n=0;n<N;n++) {
                S2[m][n] = S1[(m+i)%N][n];
            }
        }
        int flag=0;
        for(int m=0;m<N;m++) {
            for(int n=0;n<N;n++) {
                if(S2[m][n]!=S2[n][m]) flag=1;
                if(flag==0&&m==N-1&&n==N-1) ans += N;
            }
        }
    }
    cout << ans << endl;
    return 0;
}