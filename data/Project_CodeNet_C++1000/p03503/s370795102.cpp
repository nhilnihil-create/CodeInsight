#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define repr(i,n) for(int i = (int)(n); i >= 0; i--)
#define all(v) v.begin(),v.end()
typedef long long ll;

vector<int> binary(int i, int n, int N){
    int x = 1;
    rep(j,N){
        x *= n;
    }
    vector<int> vec(N);
    rep(j,N){
        x /= n;
        vec[j] = i / x;
        i -= x * vec[j];
    }
    return vec;
}

int main(){
    int N;
    cin >> N;
    vector<vector<int> > open(N,vector<int>(10));
    vector<vector<int> > profit(N,vector<int>(11));
    rep(i,N){
        rep(j,10){
            cin >> open[i][j];
        }
    }
    rep(i,N){
        rep(j,11){
            cin >> profit[i][j];
        }
    }
    int ans = -1000000007;
    vector<int> joisino(10);
    for(int i = 1; i <= 1023; i++){
        joisino = binary(i,2,10);
        int ans_sub = 0;
        rep(j,N){
            int count = 0;
            rep(k,10){
                if (open[j][k] == 1 && joisino[k] == 1) count++;
            }
            ans_sub += profit[j][count];
        }
        ans = max(ans, ans_sub);
    }
    cout << ans << endl;
}
