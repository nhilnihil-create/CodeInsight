
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define rep2(i,a,b) for (int i = (a); i < (b); ++i)


int main() {
    int a,b,c;
    cin>>a>>b>>c;

    double s = (a+b+c)/2;
    int ans = sqrt(s*(s-a)*(s-b)*(s-c));

    cout<<ans<<endl;
        
    return 0;
}

