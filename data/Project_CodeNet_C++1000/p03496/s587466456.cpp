#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
#define REP(i, n) for(int i=0; i<n; i++)

ll A[100];
int main(){
    int N;
    cin >> N;
    ll ma = -100000000;
    ll mi = 100000000;
    int mai;
    int mii;
    REP(i,N){
        ll a;
        cin >> a;
        A[i] = a;
        if(ma < a) {
            ma = a;
            mai = i;
        }
        if(mi > a) {
            mi = a;
            mii = i;
        }
    }

    cout << 2*N-1 << endl;
    ll T;
    if(ma >= 0 && mi <= 0){
        ll x;
        int y;
        bool pos;
        if(abs(ma) > abs(mi)){
            x = ma;
            y = mai;
            pos = true;
        }
        else{
            x = mi;
            y = mii;
            pos = false;
        }
        for(int i = 0; i < N; i++){
            printf("%d %d\n", y+1, i+1);
        }
        if(pos){
            for(int i = 1; i < N; i++)
                printf("%d %d\n", i, i+1);
        }
        else{
            for(int i = N-1; i > 0; i--)
                printf("%d %d\n", i+1, i);
        }
    }
    else if(ma >= 0 && mi >= 0){
        ll x = ma;
        int y = mai;
        for(int i = 0; i < N; i++){
            printf("%d %d\n", y+1, i+1);
        }
        for(int i = 1; i < N; i++)
            printf("%d %d\n", i, i+1);
    }
    else{
        ll x = mi;
        int y = mii;
        for(int i = 0; i < N; i++){
            printf("%d %d\n", y+1, i+1);
        }
        for(int i = N-1; i > 0; i--)
            printf("%d %d\n", i+1, i);
    }
    return 0;
}
