#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 3e5+5;

const int mod = 1e9+7;

int n;
int k;
int h[N];

int main(){
    scanf("%d%d " , &n , &k);
    for(int i = 1; i <= n; i++){
        scanf("%d" , &h[i]);
    }
    int mn = 1e9;
    sort(h + 1 , h + n + 1);
    for(int i = 1; i <= n; i++){
        if(i + k - 1 <= n){
            mn = min(mn , h[i + k - 1] - h[i]);
        }
    }
    printf("%d\n" , mn);
}
