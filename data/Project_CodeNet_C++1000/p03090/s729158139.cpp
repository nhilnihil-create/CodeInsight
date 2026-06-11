#include <bits/stdc++.h>
#include <math.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const ll mod = 1000000007;
const int INF = 1001001001;
const ll LINF = 1001001001001001001;
vector<pair<ll,ll>> ans;

int f(int x, int y, int z){
    if(y==3){
        ans.push_back(make_pair(1,3));
        ans.push_back(make_pair(2,3));
        return 0;
    }
    if(x+y==z){
        ans.push_back(make_pair(x,x+1));
        ans.push_back(make_pair(x,x+2));
        ans.push_back(make_pair(y,y-1));
        ans.push_back(make_pair(y,y-2));
        return 0;
    }
    if(x==1 && y%2==1){
        for(int i=1;i<y;i++){
            ans.push_back(make_pair(y,i));
        }
        f(1,y-1,z-y);
        return 0;
    }
    for(int i=x+1;i<y;i++){
        ans.push_back(make_pair(x,i));
        ans.push_back(make_pair(y,i));
    }
    f(x+1,y-1,z-x-y);
    return 0;
}

int main(){
    ll n ; cin >> n;
    f(1,n,n*(n-1)/2 - (n%2==0));
    ll m = ans.size();
    cout << m << endl;
    rep(i,m){
        cout << ans.at(i).first << " " << ans.at(i).second << endl;
    }
    return 0;
}
