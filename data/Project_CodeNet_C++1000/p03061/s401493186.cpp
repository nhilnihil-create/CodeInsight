#include <stdio.h>
#include <utility>
#include <iostream>
#include <bitset>

#define max_n (1<<27)
using namespace std;

int N;
int dat[max_n];

int gcd(int _a , int _b){
    if(_a < _b) std::swap(_a, _b);
    if(_a % _b == 0){
        return _b;
    }else{
        return gcd(_b, _a % _b);
    }
}

void show(int _n){
    int step = 2;
    for(int i = 0; i < 2*_n -1; i++){
       cout << dat[i] << " ";
        if (i == 0){
            printf("\n");
        }else if( i % step== 0){
            printf("\n");
            step = 2*step + 2;
        }
    }
}
int query(int a, int b, int k, int l, int r){
    // printf("a = %d, b = %d, k = %d , l = %d, r = %d\n", a,b,k,l,r);
    if ( r <= a || b <= l){
        return -1;
    }
    if ( a <= l && r <= b){
        return dat[k];
    }else{
        int vl = query(a, b, k*2+1, l, (l+r)/2);
        int vr = query(a, b, k*2+2, (l+r)/2, r);
        // printf("vl = %d, vr = %d\n", vl,vr);
        if (vl == -1 && vr == -1){
            return -1;
        }else if(vl == -1){
            return vr;
        }else if(vr == -1){
            return vl;
        }else{
            return gcd(vl,vr);
        }
    }
}

int main(){
    cin >> N;
    int n = 1;
    while (n < N){n = 2*n;}
    for(int i = 0; i<n; i++){
        if (i < N){
            cin >> dat[n-1 + i];
        }else{
            dat[n-1 + i] = dat[n-1 + i-1] ;
        }
    }
    // show(n);

    for(int i = n-2; i>=0; i--){
        dat[i] = gcd(dat[2*i+1], dat[2*i+2]);
    }
    // show(n);

    int ans = 0;
    // printf(" solve \n");
    for(int i = 0; i<N; i++){
        // i を省いた時の値を調べていく
        // cout << "i : "<< i << endl;
        if (i==0){
            ans = max(ans, query(1, N, 0, 0, n));
        }else if(i==N-1){
            ans = max(ans, query(0, N-1, 0, 0, n));
        }else{
            ans = max(ans, gcd(query(0, i, 0, 0, n), query(i + 1, N, 0, 0, n)));
        }
    }
    cout << ans << endl;
    return 0;
}