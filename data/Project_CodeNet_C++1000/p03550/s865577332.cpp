#include <bits/stdc++.h>
#define ll long long
#define rep(X,N) for(ll X = 0; X < (N); X++)
#define PI (acos(-1.0))
#define pback push_back
#define mpair make_pair
#define divceil(A, B) ((A + (B - 1)) / B)
#define MODN 1000000007
#define ALL(V) (V).begin(),(V).end()
#define CERR if(false) cerr

using namespace std;

int main(){

    int n,z,w;
    cin >> n >> z >> w;

    //zは不必要な情報のはず

    //便宜上、ここにwを置いても問題ないはず
    vector<int> a(1,w);

    rep(i,n){
        int tmp;
        cin >> tmp;
        a.pback(tmp);
    }

    vector<vector<int>> v(n + 1, vector<int>(n + 1, -1));

    //x=nのばあい

    for(int i = n - 1; i >= 0; i--){
        v[n][i] = abs(a[i] - a[n]);
    }

    //y=nのばあい
    for(int i = n - 1; i >= 1; i--){
        v[i][n] = abs(a[i] - a[n]);
    }

    for(int k = n - 1; k >= 1; k--){


        int tmpscore = INT_MAX;

        for(int j = n; j > k; j--){
            tmpscore = min(tmpscore, v[k][j]);
        }

        for(int j = k - 1; j >= 0; j--){
            v[k][j] = tmpscore;
        }

        tmpscore = 0;

        for(int i = n; i > k; i--){
            tmpscore = max(tmpscore, v[i][k]);
        }

        for(int i = k - 1; i > 0; i--){
            v[i][k] = tmpscore;
        }
    }

    int ans = 0;

    for(int i = n; i > 0; i--){
        ans = max(ans, v[i][0]);
    }

    cout << ans << endl;

    return 0;
}