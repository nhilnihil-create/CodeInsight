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
    int a,b,ans=0;
    cin>>a>>b;
    repi(i,a,b+1){
        int rev=i%10*10000+(i%100/10)*1000+(i%1000/100)*100+(i%10000/1000)*10+i/10000;
        if(i==rev) ans++;
    }
    cout<<ans;
}