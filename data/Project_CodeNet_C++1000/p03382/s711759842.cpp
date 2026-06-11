#include <bits/stdc++.h>
using namespace std;
#define MAX 100002
typedef long long ll;
ll N, a[MAX];

int main(){
    scanf("%lld", &N);
    for(int i = 1; i <= N; i++)
        scanf("%lld", a + i);
    sort(a + 1, a + N + 1, [](const ll &x, const ll &y){
        return x > y;
    });
    ll ans = 0;
    ll mn = 1e9;
    for(int i = 2; i <= N; i++){
        if(abs(a[1] / 2 - a[i]) < mn){
            mn = abs(a[1] / 2 - a[i]);
            ans = a[i]; 
        }
    }
    printf("%lld %lld\n", a[1], ans);
    return 0;
}