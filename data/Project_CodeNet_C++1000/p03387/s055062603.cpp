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
    vector<int> s(3);
    rep(i,3) cin>>s[i];
    sort(all(s));
    int a=s[2],b=s[1],c=s[0],cnt=0;
    if((a-b)%2==(a-c)%2) cnt=a-b+(b-c)/2;
    else cnt=a-b+(b-c+1)/2+1;
    cout<<cnt;
}