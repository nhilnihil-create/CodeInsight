#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <iomanip>
#include <map>
#include <set>
#include <cmath>
#include <cstdio>
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define FOR(i,m,n) for(int (i)=(m);(i)<(n);(i)++)
#define All(v) (v).begin(),(v).end()
typedef long long ll;

int main(){
    int n;cin >> n;
    vector<int> a(n);
    rep(i,n)cin >> a[i];
    sort(All(a));
    int m=a[n-1];
    int p = lower_bound(a.begin(),a.end()-1,m/2.0)-a.begin();
    int res = a[p];
    if(p>0)if(abs(a[p-1]-m/2.0)<abs(a[p]-m/2.0)||res==m)res = a[p-1]; 
    cout << m << ' ' << res << endl;
    return 0;
}