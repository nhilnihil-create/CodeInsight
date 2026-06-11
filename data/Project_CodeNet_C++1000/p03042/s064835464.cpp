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
    int s;
    cin>>s;
    int a=s/100,b=s%100;
    if(1<=a&&a<=12){
        if(1<=b&&b<=12) cout<<"AMBIGUOUS";
        else cout<<"MMYY";
    }
    else{
        if(1<=b&&b<=12) cout<<"YYMM";
        else cout<<"NA";
    }
}