#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(i, n) for (int i = 1; i < (int)(n+1); i++)
int main() {
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    cout<<c-(d-b)<<" "<<d+(c-a)<<" "<<a-(d-b)<<" "<<b+(c-a)<<endl;
}
