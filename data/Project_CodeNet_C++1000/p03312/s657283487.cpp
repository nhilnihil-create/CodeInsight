#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define int64 long long
#define debug(x) cerr << #x << " is " << x << endl;
#define MaxN 300000

int64 P, Q, R, S, maxim, minim, res;
int64 pr[MaxN+1];
int64 su[MaxN+1];
int v[MaxN+1];
int N;

void test(int st, int i, int dr)
{
    P = pr[st];
    Q = su[st+1] - su[i+1];
    R = pr[dr] - pr[i];
    S = su[dr+1];

    maxim = max(max(max(P, Q), R), S);
    minim = min(min(min(P, Q), R), S);
    res = min(res, maxim - minim);
}

int main(){


    int i, st, dr, mid, pos1, pos2;
    res = 1LL << 62;

    scanf("%d", &N);
    for(i = 1; i <= N; ++i) scanf("%d", &v[i]);
    for(i = 1; i <= N; ++i) pr[i] = pr[i-1] + v[i];
    for(i = N; i >= 1; --i) su[i] = su[i+1] + v[i];
    for(i = 2; i < N-1; ++i)
    {
        pos1 = 1;
        for(st = 1, dr = i-1; st <= dr; )
        {
            mid = (st + dr) / 2;
            if(pr[mid] > su[mid+1] - su[i+1]) dr = mid - 1;
            else{
                st = mid + 1;
                pos1 = mid;
            }
        }

        pos2 = i+1;
        for(st = i+1, dr = N-1; st <= dr; )
        {
            mid = (st + dr) / 2;
            if(pr[mid] - pr[i] > su[mid+1]) dr = mid - 1;
            else{
                st = mid + 1;
                pos2 = mid;
            }
        }

        test(pos1, i, pos2);
        if(pos1 + 1 < i) test(pos1 + 1, i, pos2);
        if(pos2 + 1 < N) test(pos1, i, pos2 + 1);
        if(pos1 + 1 < i && pos2 + 1 < N) test(pos1 + 1, i, pos2 + 1);
    }

    printf("%I64d\n", res);


return 0;
}
