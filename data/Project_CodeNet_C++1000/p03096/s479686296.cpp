#include <bits/stdc++.h>
using namespace std;

int previnst[200005];

int main(){
    int n;
    scanf("%d", &n);
    int pmatch[n];
    long long waystofin[n+1];
    for(int i = 0; i < 200005; i++){
        previnst[i] = -1;
    }
    for(int i = 0; i < n; i++){
        waystofin[i] = 0;
        int col;
        scanf("%d", &col);
        pmatch[i] = previnst[col];
        previnst[col] = i;
    }
    waystofin[n] = 1;
    for(int i = n-1; i >= 0; i--){
        waystofin[i] += waystofin[i+1];
        waystofin[i] %= 1000000007;
        if(pmatch[i] != -1 && pmatch[i] != i-1){
            waystofin[pmatch[i]] += waystofin[i];
        }
    }
    printf("%lld", waystofin[0]);
}
