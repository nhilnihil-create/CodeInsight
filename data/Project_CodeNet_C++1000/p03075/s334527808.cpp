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

ll a[5],k;

int main(){
    for(int i = 0; i < 5; i++)  cin >> a[i];
    cin >> k;
    sort(a,a+5);
    if(a[4]-a[0] <= k)  cout << "Yay!\n";
    else{
        cout << ":(\n";
    }
}