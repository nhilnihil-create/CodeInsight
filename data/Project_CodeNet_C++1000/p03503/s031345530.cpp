#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<vector>
#include<utility>
#include<queue>
#include<deque>
#include<stack>
#include<set>
#include<map>
#include<bitset>
#include<string>
#define mod 1000000007
typedef long long ll;
using namespace std;

int main(){
    int n; cin >> n;
    int F[105][5][2];
    ll P[105][15];
    for(int i=0;i<n;i++){
        for(int j=0;j<5;j++){
            for(int k=0;k<2;k++){
                cin >> F[i][j][k];
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<=10;j++){
            cin >> P[i][j];
        }
    }

    ll ans = -100100100100100100;
    int shift[5][2];
    for(int m=0;m<(1<<10);m++){
        int cnt = 0;
        for(int i=0;i<5;i++){
            for(int j=0;j<2;j++) shift[i][j] = 0;
        }

        for(int j=0;j<10;j++){
            cnt += (m >> j) & 1;
            shift[j/2][j%2] = (m >> j) & 1;
        }
        if(cnt < 1) continue;

        int count[105];
        for(int i=0;i<n;i++) count[i] = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<10;j++){
                count[i] += (shift[j/2][j%2] & F[i][j/2][j%2]);
            }
        }

        ll rep = 0;
        for(int i=0;i<n;i++) rep += P[i][count[i]];

        ans = max(ans, rep);
    }
    
    cout << ans << endl;
    return 0;
}