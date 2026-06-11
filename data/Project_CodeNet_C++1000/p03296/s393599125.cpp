#include <bits/stdc++.h>
#include <stdio.h>
#include <cmath>
#include <tgmath.h>

using namespace std;

#define rep(i,n) for(long long i=0; i<(long long)(n);i++)
//rep…「0からn-1まで」の繰り返し
#define rep2(i,s,n) for(long long i=s; i<=(long long)(n);i++)
//rep2…「sからnまで」の繰り返し
#define repr(i,s,n) for(long long i=s;i>=(long long)(n);i--)
//repr…「ｓからnまで」の降順の繰り返し

typedef long long ll;

const ll inf = 1e18+7;
const ll mod = 1e9+7;


int main() {
    int n,ans=0;
    cin>>n;

    vector<int>a(n);
    rep(i,n)cin>>a[i];

    rep(i,n-1){
        if(a[i]==a[i+1]){
            a[i+1]=200;
            ans++;
        }
    }


    cout<<ans<<endl;
}
