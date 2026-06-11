#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

const long MOD = 1000000007;
typedef pair<int, int> P;
typedef long long ll;

int main(){
    int N;
    cin >> N;

    int sum[N+1][N+1];
    for(int i=0; i<=N; i++){
        for(int j=0; j<=N; j++){
            sum[i][j] = 0;
        }
    }

    for(int i=2; i<=N; i++){
        int t = i;
        for(int j=2; j<=i; j++){
            if(t%j != 0) continue;
            int cnt = 0;
            while(t%j == 0){
                t /= j;
                cnt++;
            }
            sum[i][j] = cnt;
        }
    }

    for(int i=0; i<N; i++){
        for(int j=0; j<=N; j++){
            sum[i+1][j] += sum[i][j];
            // cout << i+1 << " " << j << " " << sum[i][j] << endl;
        }
    }

    int ans = 0;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            for(int k=j+1; k<=N; k++){
                if(i==j || j==k || i==k) continue;
                if(sum[N][i]>=2 && sum[N][j]>=4 && sum[N][k]>=4){
                    // cout << i << " " << j << " " << k << endl;
                    ans++;
                }
            }
        }
    }
    for(int i=1; i<=N; i++){
        if(sum[N][i]>=74) ans++;
        for(int j=1; j<=N; j++){
            if(i==j) continue;
            if(sum[N][i]>=14 && sum[N][j]>=4) ans++;
            if(sum[N][i]>=24 && sum[N][j]>=2) ans++;
        }
    }

    cout << ans << endl;

    return 0;
}
