#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=ll(b);i--)
#define FORA(i,I) for(const auto& i:I)
#define ALL(x) x.begin(),x.end() 
#define SIZE(x) ll(x.size()) 

int main(void)
{
    int H,W;
    cin >> H >> W;

    vector<string> S(H);

    vector<int> dx{1, 0,-1, 0, 1,-1,-1, 1};
    vector<int> dy{0, 1, 0,-1, 1, 1,-1,-1};

    REP(i,H){
        cin >> S[i];
    }

    //.を0に
    REP(i,H){
        REP(j,W){
            if(S[i][j] == '.'){
                S[i][j] = '0';
            }
        }
    }

    REP(i,H){
        REP(j,W){
            if(S[i][j] == '#'){
                continue;
            }

            int num = 0;
            REP(k,8) {
                const int ni = i + dy[k];
                const int nj = j + dx[k];

                if((ni < 0) || (H <= ni) || (nj < 0) || (W <= nj)){
                    continue;
                }

                if(S[ni][nj] == '#'){
                    num++;
                }
            }

            S[i][j] = '0' + num;
        }
    }

    REP(i,H) {
        cout << S[i] << endl;
    }

    return 0;
}
