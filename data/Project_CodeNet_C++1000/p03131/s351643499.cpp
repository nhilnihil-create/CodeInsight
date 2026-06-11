#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i=0;i<(n);++i)
#define repi(i,a,b) for(int i=int(a);i<int(b);++i)
#define all(x) (x).begin(), (x).end()
#define PI 3.14159265358979323846264338327950L
using namespace std;
typedef long long ll;
typedef long double ld;
int main() {
    ll k,a,b;
    cin>>k>>a>>b;
    ll bisket=1;
    if(b-a<=2) bisket+=k;
    else{
        bisket+=a-1;
        k-=a-1;
        if(k%2==1) bisket++,k--;
        bisket+=(b-a)*(k/2);
    }
    cout<<bisket;
}