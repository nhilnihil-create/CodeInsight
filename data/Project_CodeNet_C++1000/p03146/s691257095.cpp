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
    int s,cnt=1; cin>>s;
    vector<int> a(1000010);
    while(1){
        a[s]++;
        if(a[s]>=2) break;
        if(s%2==0) s=s/2;
        else s=3*s+1;
        cnt++;
    }
    cout<<cnt;
}