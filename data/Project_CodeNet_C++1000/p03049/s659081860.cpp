//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)
#define VL vector<ll>
#define VS vector<string>
#define VB vector<bool>
#define VP vector<pair<ll,ll>>
#define VVL vector<vector<ll>>
#define VVP vector<vector<pair<ll,ll>>>
#define PL pair<ll,ll>
#define ALL(v) (v).begin(), (v).end()
ll MOD=1000000007;
ll mod=998244353;
int inf=1000001000;
ll INF=1e18+5;

int main(){
    ll N;
    cin >> N;
    VS S(N);
    ll cnt=0;
    ll c1=0,c2=0,c3=0;
    rep(i,0,N){
        cin >> S[i];
        rep(j,0,S[i].size()-1){
            if(j!=S[i].size()-1)if(S[i][j]=='A'&&S[i][j+1]=='B')cnt++;
        }
        if(S[i][S[i].size()-1]=='A'&&S[i][0]=='B'){
            c1++;
        }
        else if(S[i][S[i].size()-1]!='A'&&S[i][0]=='B'){
            c2++;
        }
        else if(S[i][S[i].size()-1]=='A'&&S[i][0]!='B'){
            c3++;
        }
    }
    ll ans=0;
    if(c1==0)ans=cnt+min(c2,c3);
    else if(c1!=0){
        if(c2+c3>0)ans=cnt+c1+min(c2,c3);
        else if(c2+c3==0)ans=cnt+c1-1;
    }
    cout << ans << endl;
    return 0;
}