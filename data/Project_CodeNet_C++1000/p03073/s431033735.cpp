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
    string s;
    int cnt=0;
    cin>>s;
    int n=s.size();
    rep(i,n)cnt+=(i+s[i])%2;//0101…にするのに必要な手数
    cout<<min(cnt,n-cnt)<<endl;//0101…と1010…の手数少ないほう出力
}