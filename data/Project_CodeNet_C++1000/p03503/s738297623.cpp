#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
#include<queue>
#include<map>
#define all(x) (x).begin(),(x).end()
typedef long long ll;
 
using namespace std;

int main(){
    int N, nmax, tmp;  cin >> N;
    int f[N][10];
    int p[N][11];
    for(int i=0; i<N; i++){
        for(int j=0; j<10; j++) cin >> f[i][j];
    }
    for(int i=0; i<N; i++){
        for(int j=0; j<11; j++) cin >> p[i][j];
    }
    nmax = pow(2,10);

    ll ans, ans1;
    ans = -200000000000LL;
    for(int i=1; i<nmax; i++){
        tmp = i;
        ans1 = 0;
        int c[N];
        for(int j=0; j<N; j++)  c[j] = 0;
        for(int j=0; j<10; j++){
            if(tmp%2==1){
                for(int k=0; k<N; k++){
                    if(f[k][j] == 1)    c[k]++;
                }
            }
            tmp /= 2;
        }
        for(int j=0; j<N; j++){
            ans1 += p[j][c[j]];
        }
        ans = max(ans,ans1);
    }
    cout << ans << endl;
    return 0;
}