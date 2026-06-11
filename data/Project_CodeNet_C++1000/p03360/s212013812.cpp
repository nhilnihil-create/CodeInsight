
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define rep2(i,a,b) for (int i = (a); i < (b); ++i)

#define INF 100000000



int main(){
    int a,b,c,k;
    cin>>a>>b>>c>>k;
    int m = max({a,b,c});
    int n = m*pow(2,k);

    cout << a+b+c-m+n <<endl;

    return 0;
}
