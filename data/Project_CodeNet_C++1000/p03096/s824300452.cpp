#include <bits/stdc++.h>
#define For(i, a, b) for (int i = a; i <= b; i++)
using namespace std;
const int mod = 1000000000 + 7, MAXN = 200000 + 5;
int val[MAXN], lastF[MAXN];
int main(){
    int n;
    scanf("%d", &n);
    val[0] = 1;
    For(i, 1, n){
        int k;
        scanf("%d", &k);
        val[i] = val[i - 1];
        if (lastF[k] && lastF[k] + 1 != i) val[i] = (val[i] + val[lastF[k]]) % mod;
        lastF[k] = i;
    }
    printf("%d", val[n]);
}