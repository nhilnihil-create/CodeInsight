#include <bits/stdc++.h>

using namespace std;
using namespace std;
#define rep(i,n) for(long long i=0; i<(long long)(n);i++)
//rep…「0からn-1まで」の繰り返し
#define rep2(i,s,n) for(long long i=s; i<=(long long)(n);i++)
//rep2…「sからnまで」の繰り返し
#define repr(i,s,n) for(long long i=s;i>=(long long)(n);i--)
//repr…「ｓからnまで」の降順の繰り返し

typedef long long ll;

const ll inf = 1e9+7;
const ll mod = 1e9+7;

int main(){
    int n;
    cin>>n;
    vector<int>a1(n),a2(n),A1(n),A2(n);

    rep(i,n)cin>>a1[i];
    rep(i,n)cin>>a2[i];

    A1[0]=a1[0];
    A2[n-1]=a2[n-1];


    rep2(i,1,n-1)A1[i]=a1[i]+A1[i-1];
    repr(i,n-2,0)A2[i]=a2[i]+A2[i+1];

    int ans=0;

    rep(i,n)ans=max(ans,A1[i]+A2[i]);

    cout<<ans<<endl;

}
