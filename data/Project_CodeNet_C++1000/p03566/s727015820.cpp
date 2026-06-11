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
    vector<int> t(n),v(n);
    rep(i,n){
        cin >> t[i];
        t[i]*=2;
    }
    rep(i,n)cin >> v[i];
    rep(i,n-1)t[i+1]+=t[i];
    
    int t_max = t[n-1];
    vector<double> v1(t_max+1,0.0),v2(t_max+1,0.0);
    int now=0;
    rep(i,t_max){
        if(t[now]==i)now++;
        v1[i+1]=min((double)v[now],v1[i]+0.5);
    }
    for(int i=t_max;i>0;i--){
        if(t[now-1]==i)now--;
        v2[i-1]=min((double)v[now],v2[i]+0.5);
    }

    double res = 0;
    rep(i,t_max+1)res+=min(v1[i],v2[i]);
    cout << fixed << setprecision(5) << res/2 <<endl;
    return 0;
}