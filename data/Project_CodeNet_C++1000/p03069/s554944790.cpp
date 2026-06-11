/*
 2020/01/26 difficulty 944
 https://atcoder.jp/contests/tenka1-2019-beginner/tasks/tenka1_2019_c
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define INF (1LL<<50)
#define MOD 1000000007

int main(){
    int N;
    cin >> N;
    string S;
    cin >> S;
    int WTcnt=0;
    for(int i=0;i<N;i++){
        if(S[i]=='.'){
            WTcnt++;
        }
    }
    int ans = WTcnt;
    int BK=0;
    int WT=0;
    for(int i=0;i<N;i++){
        if(S[i]=='.'){
            WT++;
        }else{
            BK++;
        }
        ans = min(ans,WTcnt-WT+BK);
    }
    cout << ans << endl;
    return 0;
}