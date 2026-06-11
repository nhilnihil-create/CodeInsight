#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N; string S; cin >> N >> S;
    vector<int> cntb(N+1,0),cntw(N+1,0);
    for (int i=0;i<N;++i) cntb[i+1]=cntb[i]+(S[i]=='#');
    for (int i=N-1;i>=0;--i) cntw[i]=cntw[i+1]+(S[i]=='.');
    int ans=N;
    for (int i=0;i<=N;++i) ans=min(ans,cntb[i]+cntw[i]);
    cout << ans << '\n';
}