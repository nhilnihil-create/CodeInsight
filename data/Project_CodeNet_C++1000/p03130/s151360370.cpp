#include <bits/stdc++.h>

using namespace std;
#define _for(i,j,N) for(int i = (j); i < (N);i++)
#define _rep(i,j,N) for(int i = (j); i <= (N);i++)
#define _dec(i,j,N) for(int i = (N-1);i >= 0;i--)
#define _dep(i,j,N) for(int i = (N); i>= 0;i--)
#define ALL(x) x.begin(),x.end()
#define LL long long
#define ULL unsigned LL
#define PB push_back

int cnt[5];
int main()
{
    memset(cnt,0,sizeof(cnt));
    _for(i,0,6){
        int num;cin >> num;
        cnt[num]++;
    }

    int cnt1 = 0;
    int cnt2 = 0;
    _rep(i,1,4){
        if(cnt[i] == 1) cnt1++;
        if(cnt[i] == 2) cnt2++;
    }
    if(cnt1 == 2 && cnt2 == 2){
        printf("YES\n");
    }else{printf("NO\n");}
}