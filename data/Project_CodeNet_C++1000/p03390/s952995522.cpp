#include <bits/stdc++.h>
using namespace std;

long long root(long long n){
    long long ret = pow((long double)n, 0.5L);
    while(ret*ret > n) ret--;
    while((ret+1)*(ret+1) <= n) ret++;
    return ret;
}

int main(){
    long long i, j, k;
    int Q;
    cin >> Q;
    for(i=0; i<Q; i++){
        long long A, B;
        cin >> A >> B;
        if(A>B) swap(A, B);
        long long R = root(A*B-1);
        long long ans = A-1 + max(R-A, 0LL) + (A*B-1)/(R+1);
        cout << ans << endl;
    }
    return 0;
}