#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 2e5+5;


int n , k;
int ar[N];
int cnt[N];

int main(){
    int dif = 0;
    scanf("%d%d" , &n , &k);
    for(int i = 1; i <= n; i++){
        scanf("%d" , &ar[i]);
        if(cnt[ar[i]] == 0)
            dif ++;
        cnt[ar[i]]++;

    }
    if(dif <= k){
        puts("0");
        return 0;
    }
    vector < int > all;
    for(int i = 1; i <= n; i++){
        if(cnt[ar[i]]){
            all.push_back(cnt[ar[i]]);
            cnt[ar[i]] = 0;
        }
    }
    sort(all.begin() , all.end());
    int ans = 0;
    for(auto v : all){
        ans += v;
        dif--;
        if(dif <= k)
            break;
    }
    printf("%d\n" , ans);
}
