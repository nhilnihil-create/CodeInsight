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
    ll k,a,b;
    cin>>k>>a>>b;

    ll have=1;

    if(b-a<=2) have+=k;

    else {
        k-=a-1;
        have+=a-1;

        have+=k/2*(b-a);
        if(k%2) have++;
    }

    cout<<have<<endl;

}
