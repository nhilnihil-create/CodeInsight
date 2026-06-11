#include <bits/stdc++.h>
using namespace std;
#define rep(i, ini, n) for (int i = ini; i < n; i++)
#define _rep(i, ini, n) for (int i = ini; i >= n; i--)
#define ToEnd(a) a.begin(), a.end()
uint64_t MOD = 1000000007;

int64_t N;

bool Include(string S, int n){
    char c='0'+n;
    if(S.find(c)==string::npos) return false;
    else return true;
}

bool Check(int64_t num){
    string S=to_string(num);
    return Include(S,3) && Include(S,5) && Include(S,7);
}

void Solve(int64_t &ans, int64_t n=0, int i=1){
    if(i>10) return;

    if(n<=N && Check(n)) ans++;

    Solve(ans,10*n+3,i+1);
    Solve(ans,10*n+5,i+1);
    Solve(ans,10*n+7,i+1);
}

int main()
{
    cin >> N;

    int64_t ans = 0;
    Solve(ans);

    cout<<ans<<endl;
}