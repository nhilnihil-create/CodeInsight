#include <bits/stdc++.h>

using namespace std;
#define rep(i,n) for(long long i=0; i<(long long)(n);i++)
//rep…「0からn-1まで」の繰り返し
#define rep2(i,s,n) for(long long i=s; i<=(long long)(n);i++)
//rep2…「sからnまで」の繰り返し
#define repr(i,s,n) for(long long i=s;i>=(long long)(n);i--)
//repr…「ｓからnまで」の降順の繰り返し

typedef long long ll;

const int inf = 1e9+7;
const int mod = 1e9+7;


int main(){
    int n,q;
    string s;
    cin>>n>>q>>s;

    vector<int>l(q),r(q),L(n),R(n);

    rep(i,q)cin>>l[i]>>r[i];

    rep2(i,1,n-1){
        if(s[i-1]=='A'&&s[i]=='C')L[i]+=L[i-1]+1;
        else L[i]=L[i-1];
    }

    repr(i,n-2,0){
        if(s[i]=='A'&&s[i+1]=='C')R[i]+=R[i+1]+1;
        else R[i]=R[i+1];
    }

    int all=R[0];
    rep(i,q)cout<<all-R[r[i]-1]-L[l[i]-1]<<endl;

}
