#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 2e5+5;

int n;
int k;
int ar[N];
int cnt[N];

int main(){
    scanf("%d%d " , &n , &k);
    int mn = 2e9;
    for(int i = 1; i <= n; i++){
        scanf("%d" , &ar[i]);
        mn = min(mn , ar[i]);
        cnt[ar[i]]++;
    }
    k--;
    long long ans = ( n - cnt[mn] + k - 1 ) / (k);
    //cout << n - cnt[mn] + 1 << "\n";
    printf("%lld\n" , ans);
}
