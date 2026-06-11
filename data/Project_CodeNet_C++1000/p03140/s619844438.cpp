#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
typedef long long ll;
const int MOD = 1000000007;
int main()
{
    int N;
    cin >> N;
    string a,b,c;
    cin >> a >> b >> c;
    int ans=0;
    rep(i,N){
        int cn=0;
        if(a[i]==b[i])cn++;
        if(a[i]==c[i])cn++;
        if(b[i]==c[i])cn++;
        if(cn==0)ans+=2;
        else if(cn==1)ans+=1;
    }
    cout << ans << endl;
    return 0;
}