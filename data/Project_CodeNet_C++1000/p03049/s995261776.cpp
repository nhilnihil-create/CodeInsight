#include <bits/stdc++.h>
#define int long long
typedef long long ll;
using namespace std;

const ll MAXN = 10000;

ll N, ans=0, tmp1=0, tmp2=0, tmp3=0;
string A[MAXN];

signed main(){
    cin >> N;
    for(int i=0;i<N;i++) cin >> A[i];
    for(int i=0;i<N;i++) {
        for(int j=0;j<A[i].size()-1;j++) {
            if(A[i][j]=='A'&&A[i][j+1]=='B') {
                A[i][j] = 'C';
                A[i][j+1]= 'C';
                ans++;
            }
        }
        if(A[i][0]=='B') tmp1++;
        if(A[i][A[i].size()-1]=='A') tmp2++;
        if(A[i][0]=='B'&&A[i][A[i].size()-1]=='A') tmp3++;
    }
    if(tmp2<tmp1) ans+=tmp2;
    else ans+=tmp1;
    if(tmp3!=0&&tmp1==tmp3&&tmp2==tmp3) ans--;
    cout << ans << endl;
    return 0;
}