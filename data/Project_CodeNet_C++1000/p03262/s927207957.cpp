#include<bits/stdc++.h>
#define F first
#define S second
#define MAX(a,b) (a>b? a:b)
#define MIN(a,b) (a>b? b:a)
#define all(x) (x).begin(), (x).end()
#define rep(i,n) for(lint i=0;i<(lint)(n);i++)
#define rep2(i,a,b) for(lint i=a;i<(lint)(b);i++)
#define PICK(N,m,p) (N/(int)(pow(p,m-1))-(N/(int)(pow(p,m)))*p)
using lint = long long;
using ld = long double;
using namespace std;

lint gcd(lint x,lint y){
    lint a=MAX(x,y);
    lint b=MIN(x,y);
    if(b==0) return a;
    else {
        lint q=a/b;
        lint g=gcd(b,a-q*b);
        return g;
    }
}

int main(){
    int N, X;
    lint x[100001];
    cin >> N >> X;
    rep(i,N) cin >> x[i];
    lint d[100001];
    rep(i,N) d[i]=abs(x[i]-X);
    lint D=1;
    D=d[0];
    rep(i,N-1) D=gcd(d[i+1],D);
    cout << D << endl;
	return 0;
}