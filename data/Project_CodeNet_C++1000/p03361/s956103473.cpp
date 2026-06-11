#include <bits/stdc++.h>
#define REP(i,n) for(ll i=0;i<(ll)(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=(ll)(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=(ll)(b);i--)
#define ALL(x) (x).begin(),(x).end() 
#define SIZE(x) ((ll)(x).size())
#define MAX(x) *max_element(ALL(x))
#define MIN(x) *min_element(ALL(x))
#define INF 1000000000
using namespace std;
typedef long long ll;

int main() {
    int H, W;
    cin >> H >> W;

    string S[H];
    REP(i, H){
        cin >> S[i];
    }

    vector<vector<int>> field(H+2, vector<int>(W+2));

    FOR(i, 1, H){
        FOR(j, 1, W){
            if (S[i-1][j-1] == '#'){
                field[i][j] = 1;
            }
            //cout << field[i][j] << endl;
        }
    }

    int res;
    bool flag = true;
    FOR(i, 1, H){
        FOR(j, 1, W){
            res = 0;
            if (S[i-1][j-1] == '#'){
                res += (field[i][j-1] + field[i][j+1] + field[i-1][j] + field[i+1][j]);
                //cout << res << endl;
                if (res == 0){
                    flag = false;
                }
            }
        }
    }

    if (flag == true){
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }
}
