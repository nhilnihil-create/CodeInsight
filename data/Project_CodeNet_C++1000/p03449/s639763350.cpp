#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
typedef long long ll;



int main(void)
{
    int N,ans = 0,sum;
    cin >> N;
    vector<vector<int>> a(2,vector<int>(N));

    rep(i,2){
        rep(j,N){
            cin >> a[i][j];
        }
    }

    rep(k,N){
        int i = 0;
        sum = 0;
        rep(j,N){
            sum += a[i][j];
            if(k == j){
                i = 1;
                sum += a[i][j];
            }
        }
        ans = max(ans,sum);
    }

    cout << ans << endl;
    

    return 0;
}