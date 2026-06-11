#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

int main(){
    int n,k;
    cin >> n >> k;
    ld p = 0.0;
    for(int i=1;i<=n;i++){
        int a = i;
        ld pi = 1.0/(ld)n;
        while(a < k){
            pi *= 0.5;
            a *= 2;
        }
        p += pi;
    }
    printf("%.9Lf",p);
}