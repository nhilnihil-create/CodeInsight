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
    int a,b,k;
    cin>>a>>b>>k;
    int cnt=0;
    for(int i=100;i>=1;i--){
        if(a%i==0&&b%i==0) cnt++;
        if(cnt==k){
            cout<<i; return 0;
        }
    }
}