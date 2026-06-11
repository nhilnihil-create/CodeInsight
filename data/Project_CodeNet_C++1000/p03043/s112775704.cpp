#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
using ll = long long;
using ld = long double;
#define rep2(i, s, n) for (ll i = (s); i < (ll)(n); i++)
#define rep3(i, n) for (int i = 1; i < (ll)(n+1); i++)
#define rep4(i, s, n) for (ll i = (s); i < (ll)(n+1); i++)
#define repr(i,n) for (ll i = (n-1); i>=0;i--)
#define repr3(i,n) for(ll i = (n);i>0;i--)
#define stlen(s) ll s.size()-1
#define all(v) v.begin(), v.end()
#define cout(n) cout<<std::fixed<<std::setprecision(n)
using Graph = vector<vector<int>>;
#define INF const ll INF = 1001001001;
#define PI const ld PI = 3.14159265358979323846;



int main(){
int a,b;scanf("%d%d",&a,&b);
double ret=0;
for(int i=1;i<=a;i++){
double tmp=1.0/a;
int now=i;
while(now<b){
now*=2;
tmp/=2;
}
ret+=tmp;
}
printf("%.12f\n",ret);
}