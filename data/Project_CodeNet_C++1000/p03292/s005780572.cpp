#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> P;
typedef pair<ll, ll> Pl;

const int INT_INF = 2147483646;
const ll LL_INF = 9223372036854775807;
const double PI=3.1415926535897932;

bool SecondCompare(const pair<int,int> &a,const pair<int,int> &b)
{
       return a.second<b.second;
}
 
bool SecondCompareDes(const pair<int,int> &a,const pair<int,int> &b)
{
       return a.second>b.second;
}

ll minll(ll a, ll b){
    if(a >= b)  return b;
    else    return a;
}

ll maxll(ll a, ll b){
    if(a >= b)  return a;
    else    return b;
}

ll a[3];

int main(){
    for(int i = 0; i < 3; i++)  cin >> a[i];
    sort(a,a+3);
    ll ans = 0;
    for(int i = 1; i < 3; i++){
        ans += a[i]-a[i-1];
    }
    cout << ans << endl;
}