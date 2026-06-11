/*|In The Name Of Allah|*/

#include <bits/stdc++.h>

using namespace std;

const int N = 1e5+5;

const int mod = 1e9+7;

int n;
int m;
long long cm[N];
long long rm[N];
map < long long , long long > cnt;

int main(){
    scanf("%d%d" , &n , &m);
    for(int i = 1; i <= n; i++){
        int x;
        scanf("%d" , &x);
        cm[i] = cm[i - 1] + x;
    }
    for(int i = 0; i <= n; i++){
        rm[i] = cm[i] % m;
        cnt[rm[i]]++;
    }
    long long ans = 0;
    for(auto v : cnt){
        ans += v.second * (v.second - 1) / 2;
    }
    printf("%lld\n" , ans);
}