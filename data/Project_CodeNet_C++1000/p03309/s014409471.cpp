#include <bits/stdc++.h>
#define pb push_back
#define rep(i,n) for(int i=0;i<(n);i++)
#define reps(i,n,s) for(int i=(s);i<(n);i++)
#define rrep(i,n) for(int i=(n-1);i>=0;i--)
#define rreps(i,n,s) for(int i=s;i>=n;i--)
#define MOD 1000000007
using ll = long long;
using namespace std;
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }

int main(){
cin.tie(0);
ios::sync_with_stdio(false);
int n;
cin >> n;
vector<int> a(n);

rep(i, n){
    cin >> a[i];
    a[i] = a[i]-(i + 1);
}
sort(a.begin(), a.end());
ll median;
if(a.size()%2!=0){
    median = a[(n - 1) / 2];
}
else{
    median = (a[n / 2 - 1] + a[n / 2])/2;
}
ll ans = 0;
rep(i,n){
    ans += abs(median - a[i]);
}
cout << ans << endl;
//system("pause");
return 0;
}