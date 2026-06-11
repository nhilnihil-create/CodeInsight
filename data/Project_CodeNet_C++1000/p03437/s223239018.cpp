#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define Fi first
#define Se second
#define Pb push_back

#define all(a) a.begin(),a.end()
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define Rep(i,n,m) for(int i=(int)(n);i<(int)(m);i++)
#define RepS(i,n,m) for(int i=(int)(n);i<=(int)(m);i++)
#define RRepS(i,n,m) for(int i=(int)(n);i>=(int)(m);i++)
#define RepA(x) for(auto item : (x))
#define output_s(a) printf("%s\n",(a).c_str())

//library----------------------------------------------


int main(){
    ll a,b;cin>>a>>b;
    printf("%lld\n",(a%b==0?-1:a));
    return 0;
}