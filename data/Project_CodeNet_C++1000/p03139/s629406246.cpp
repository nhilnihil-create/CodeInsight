#pragma GCC optimize("Ofast")
//#pragma comment(linker, "/STACK: 2000000")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>

#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define endl '\n'
#define elif else if
#define lli long long int
#define ld long double
#define vec vector
#define forn(a) for(lli a=0; a<n; a++)
#define all(x) x.begin(), x.end()
#define presicion(x) cout<<fixed<<setprecision(x)
#define deb(x) cerr<<#x<<" = "<<x<<endl
#define PI 3.14159265358979323
#define sen(ang) sin((ang)*PI/180)
//cout<<flush;

using namespace std;

int main(){
    IOS;

    int n, a, b;
    cin>>n>>a>>b;

    int maximo = min(n, min(a, b));
    int minimo = (a+b)>=n ? (a+b)-n : 0;
    cout<<maximo<<" "<<minimo<<endl;

    return 0;
}