#include <bits/stdc++.h>

#define rep(X,N) for(ll X = 0; X < (N); X++)
#define PI (acos(-1.0))
#define pback push_back
#define mpair make_pair
#define MODN 1000000007
#define ALL(V) (V).begin(),(V).end()
#define INT_MAX_HALF (INT_MAX / 2)
#define EPS (1e-10)

using namespace std;
typedef long long ll;

int mindiff(int bit){

    int result = INT_MAX;
    int tmp = 1;

    rep(i, 47){
        if(bit & (1<< (i % 24) + 1)){
            result = min(result, tmp);
            tmp = 1;
        }else{
            tmp++;
        }
    }

    result = min(result, tmp);

    return result;
}


int main(){

    int n;
    cin >> n;

    vector<int> d(n);

    rep(i, n){
        cin >> d[i];
    }

    vector<vector<bool>> dp(n + 1, vector<bool>(1<<24, false));

    dp[0][1] = true;

    rep(i, n){
        rep(j, (1<<24)){
            if(dp[i][j]){

                if(d[i] == 0){

                }else{

                    if(j & (1<<d[i])){

                    }else{
                        dp[i + 1][j + (1<<d[i])] = true;
                    }

                    if(j & (1<<(24 - d[i]))){

                    }else{
                        dp[i + 1][j + (1<<(24 - d[i]))] = true;
                    }

                }

            }
        }
    }

    int ans = 0;
    
    rep(i, (1<<24)){
        if(dp[n][i]){
            ans = max(ans, mindiff(i));
        }
    }

    cout << ans << endl;

}
