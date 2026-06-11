/*|In The Name Of Allah|*/

#include <bits/stdc++.h>

using namespace std;

const int N = 2e5+5;

int n;
int ar[N];
map < int , int > cnt;

int main(){
    scanf("%d" , &n);
    for(int i = 1; i <= n; i++){
        scanf("%d" , &ar[i]);
        cnt[ar[i]]++;
    }
    sort(ar + 1 , ar + n + 1);
    reverse(ar + 1 , ar + n + 1);
    int ans = 0;
    for(int i = 1; i <= n; i++){
        int x = ar[i];
        if(!cnt[x])
            continue;
        cnt[x]--;
        bool done = 0;
        for(int j = 30; j >= 0; j--){
            int pw = (1 << j) - x;
            if(pw > 0 && cnt[pw]){
                cnt[pw]--;
                ans++;
                done = 1;
                break;
            }
        }
        if(!done)
            cnt[x]++;
    }
    printf("%d\n" , ans);
}