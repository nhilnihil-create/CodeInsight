#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 1e5+5;

int n;
int m;
int ar[N];
int prefix[N];

int main(){
    scanf("%d%d " , &n , &m);
    map < int , int > cnt;
    cnt[0] = 1;
    long long ans = 0;
    for(int i = 1; i <= n; i++){
        scanf("%d" , &ar[i]);
        prefix[i] = (0LL + prefix[i - 1] + ar[i]) % m;
        ans += cnt[prefix[i]];
        cnt[prefix[i]]++;
    }
    printf("%lld\n" , ans);
}
