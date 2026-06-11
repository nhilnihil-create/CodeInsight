#include <bits/stdc++.h>
#include <string>
#include <cstring>
#include <algorithm>
#include <math.h>
#include <map>
#include <bitset>
#include <cmath>
#include <set>
#include <utility>
#include <sstream>

#define INF 1000000000000
#define MOD 1000000007 //10^9+7:合同式の法

using namespace std;
typedef long long ll;

//マクロ
#define REP(i,n) for(ll i=0;i<(ll)(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=(ll)(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=(ll)(b);i--)
#define ALL(x) x.begin(),x.end()
#define chmax(x,y) (x = max(x,y))
#define chmin(x,y) (x = min(x,y))

ll mygcd(ll x,ll y){
    if(x <= y){
        if(x == 0)
            return y;
        else
            return mygcd(y%x,x);      
    }else{
        if(y == 0)
            return x;
        else
        {
            return mygcd(y,x%y);
        }
        
    }
}


int main(){
    ll N,X;
    cin >> N >> X;
    vector<ll> A(N);

    for(int i = 0;i < N;i++)
        cin >> A.at(i);

    sort(A.begin(),A.end());

    ll min = INF;

    vector<ll>sa(N);
    for(int i = 0;i < N;i++){
        sa.at(i) = abs(X - A.at(i));
    }

    ll gcmax=-1,ans=sa.at(0);
    for(int i = 1;i < N;i++){
        ans = mygcd(ans,sa.at(i));
        if(ans > gcmax)
            gcmax=ans;
    }

    cout << ans << endl;

}