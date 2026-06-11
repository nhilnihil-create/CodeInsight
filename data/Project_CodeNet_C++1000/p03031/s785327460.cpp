#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cassert>
#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <numeric>
#include <sstream>
#include <bitset>
#define repr(i,a,b) for(int i=a;i<b;i++)
#define rep(i,n) for(int i=0;i<n;i++)
#define invrepr(i,a,b) for(int i=b-1;i>=a;i--)
#define invrep(i,n) invrepr(i,0,n)

using namespace std;
typedef long long ll;
const ll MOD=1e9+7;

int main() {
    std::ios::sync_with_stdio(0); cin.tie(0);

    ll i,j,h;

    ll n,m;
    
    ll ans = 0;
    ll temp;
    
  
    cin >> n>>m;
    vector <vector <ll> > s(m, vector<ll>(n));
    vector <ll> k;
    vector <ll> p;
    rep(i,m){
        cin >> temp;
        k.push_back(temp);

        rep(j,k[i]){
            cin >> temp;
            s[i].push_back(temp);
        }
    }
    rep(i,m){
        cin >> temp;
        p.push_back(temp);
    }
    bool flag = true;
    for (int bit = 0; bit < (1<<n); ++bit)
    {   
        flag = true;
        rep(i,m){
            temp = 0;
            rep(j,s[i].size()){
                if(bit & 1<<(s[i][j]-1))temp++;
            }
            if(!(temp%2==p[i]))flag=false;
        }

        if(flag)ans++;
    }



    cout << ans<< endl;
  
    return 0;
}