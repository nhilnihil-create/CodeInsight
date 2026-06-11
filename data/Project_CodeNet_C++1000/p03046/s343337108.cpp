#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<queue>
#include<string>
#include<cstring>
#include<algorithm>
#include<set>
#include<map>
#include<iomanip>

#define REP(i,n) for(int i=0;i<(n);i++)
#define EPS (1e-7)
#define INF (2e9)
// cout << setprecision(10)

using namespace std;
typedef long long int ll;

int M, K;
int main(void){
    cin >> M >> K;
    int C = 0;

    if(K==0) {
        REP(i, pow(2, M)) cout << i << " " << i << " ";
        cout << endl;
        return 0;
    }

    REP(i, pow(2,M)){
        if (i==K) continue;
        C ^= i;
    }
    if(C != K) {
        cout << -1 << endl;
        return 0;
    }
    REP(i, pow(2,M)) {
        if (i==K) continue;
        cout << i << " ";
    }
    cout << K << " ";
    for (int i = pow(2,M)-1;i>=0;i--){
        if (i==K) continue;
        cout << i << " ";
    }
    cout << K << endl;

    return 0;
}

