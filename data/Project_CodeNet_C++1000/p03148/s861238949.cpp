/*|In The Name of Allah|*/

#include <bits/stdc++.h>

using namespace std;

const int N = 1e5+5;

int n;
int k;
int cnt[N];
priority_queue < pair < int , int > > pq1 , pq2;

int main(){
    scanf("%d%d" , &n , &k);
    for(int i = 1; i <= n; i++){
        int t , d;
        scanf("%d%d" , &t , &d);
        pq1.push({d , t});
    }
    int took = k;
    long long x = 0 , sum = 0 , best = 0;
    while(took){
        int d = pq1.top().first;
        int t = pq1.top().second;
        pq1.pop();
        pq2.push({-d , t});
        sum += d;
        if(!cnt[t])
            x++;
        cnt[t]++;
        took--;
    }
    best = sum + x*x;
    while(pq1.size()){
        int d = pq1.top().first;
        int t = pq1.top().second;
        pq1.pop();
        if(cnt[t])
            continue;
        int tm = -1;
        while(pq2.size()){
            int d2 = -pq2.top().first;
            int t2 = pq2.top().second;
            pq2.pop();
            if(cnt[t2] > 1){
               cnt[t2] --;
               tm = d2;
               break;
            }
        }
        if(tm == -1)
          break;
        x++;
        sum -= tm;
        sum += d;
        cnt[t]++;
        best = max(best , sum + x*x);
    }
    printf("%lld\n" , best);
    return 0;
}
