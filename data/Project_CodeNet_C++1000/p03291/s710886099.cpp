#include <bits/stdc++.h>
#include <unordered_map>
#include <queue>
#define MOD 1000000007
#define REP(i,st,num)for(int i=(st);i<(num);++i)
#define ll long long
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    string S;
    int qCnt=0,n;
    ll aa[100001] = {0,};
    ll ans=0,poww=1, la = 0, lq = 0, rc = 0, rq = 0;
    cin >> S;
    n=S.length();
    aa[0]=1;
    REP(i,0,n){
        rc += S[i]=='C';
        rq += S[i]=='?';
        if(i!=0)aa[i]=(aa[i-1] * 3) % MOD;
    }
    REP(i,0,n){
        rc -= S[i]=='C';
        rq -= S[i]=='?';
        if (S[i]=='B'||S[i]=='?') {
            ll l = ((la * aa[lq]) % MOD) + ((lq * aa[lq - 1]) % MOD);
            ll r = ((rc * aa[rq]) % MOD) + ((rq * aa[rq - 1]) % MOD);
            ans = (ans + (l * r)) % MOD;
        }
        la += S[i]=='A';
        lq += S[i]=='?';
    }
    cout<<ans;
//A??C
//1233
//0122
//0123
//0122

    return 0;
}