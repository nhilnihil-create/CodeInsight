#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define REP(i, a, b) for(int i = a, i##_len = (b); i < i##_len; ++i)

int main()
{
    int N;
    scanf("%d", &N);
    pair<int, int> List[N];
    int sm = 0;
    for(int i = 0; i < N; ++i) {
        scanf("%d", &List[i].first);
        List[i].second = i;
        sm += List[i].first;
    }

    //for(int i = 0; i < N; ++i) printf("%d : %d\n", List[i].first, List[i].second);
    int res = 0, val = 1000000;
    for(int i = 0; i < N; ++i) {
        int dist = abs(sm - N*List[i].first);
        if(dist < val) res = List[i].second, val = dist;
    }
    printf("%d\n",res);
    return 0;
}