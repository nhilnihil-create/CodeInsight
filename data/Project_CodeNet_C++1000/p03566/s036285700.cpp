#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
#define REP(i, n) for(int i=0; i<n; i++)

int T[2100];
int V[2100];
#define TIME 200*100+100000
int A[2100][TIME];

int main(){
    ll N;
    cin >> N;
    T[0] = 0;
    REP(i,N){
        ll t;
        cin >> t;
        //T[i] = 2*t;
        T[i+1] = 2*t;
        T[i+1] += T[i];
    }
    T[N+1] = T[N];

    V[0] = 0;
    REP(i,N){
        ll v;
        cin >> v;
        V[i+1] = 2*v;
    }
    V[N+1] = 0;

    ll last = 0;
    REP(i,N+2){
        ll t = T[i];
        ll v = V[i];
        REP(s,TIME){
            if(s < last)
                A[i][s] = v + (last-s);
            else if(s <= t)
                A[i][s] = v;
            //else
            //    A[i][s] = v + (s - t);
            else
                A[i][s] = 3000000;
        }
        last = t;
    }

    ll v = 0;
    //ll S = 0;
    long double S = 0;
    for(int t = 1; t <= T[N+1]; t++){
        int lim = 3000000;
        for(int i = 0; i < N+2; i++){
            lim = min(lim, A[i][t]);
        }
        ll vv = v;
        if(v+1 <= lim) v++;
        else if(v > lim) v--;
        //S += min(vv, v) + 0.5*abs(vv-v);
        //S += min(vv, v);
        //if(v > vv) S += v-vv;
        S += 0.5*(vv+v);
    }

    printf("%Lf\n", S/4.0);
    return 0;
}
