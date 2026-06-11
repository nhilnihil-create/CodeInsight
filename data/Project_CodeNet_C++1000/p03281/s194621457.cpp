#include<bits/stdc++.h>
using namespace std;
typedef long long INT;
typedef vector<vector<int>> Graph;
#define MOD 1000000007
#define INF 1000000000000
#define FOR(i,a,b) for(INT i=a;i<=INT(b);i++)
#define REP(i,n) for (INT i=0;i<(INT(N));i++)
#define all(x) (x).begin,(x).end()

int judge(int n)
{
    int cnt=0;
    FOR(i,1,n){
        if (n%i==0)cnt++;
    }
    return cnt;
}


int main()
{
    int n;
    cin>>n;
    int ans=0;
    FOR(i,1,n){
        if(i%2==1){
            int cnt=judge(i);
            if(cnt==8)ans++;
        }
    }
    cout<<ans<<endl;
}