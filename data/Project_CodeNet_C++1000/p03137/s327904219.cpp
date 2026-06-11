#include <bits/stdc++.h>
#include <algorithm>
#include <map>
#include <cstdlib>
#include <cmath>
#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
typedef long long ll;
const double pi=acos(-1);

ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}

int main(){
    int n,m;
    cin >> n >> m;
    vector<int> x(m);
    for(int i=0;i<m;i++) cin >> x[i];
    if(n>=m){
        cout << 0 << endl;
        return 0;
    }
    sort(x.begin(),x.end());
    vector<int> dis(m-1);
    for(int i=0;i<m-1;i++){
        dis[i]=x[i+1]-x[i];
    }
    sort(dis.begin(),dis.end());
    for(int i=0;i<n-1;i++){
        dis.pop_back();
    }
    int ans=0;
    for(int i=0;i<dis.size();i++){
        ans+=dis[i];
    }
    cout << ans << endl;
}
