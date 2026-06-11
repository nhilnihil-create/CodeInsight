#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
#include <map>
#include <string.h>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)

int main()
{
ll a,b,c;
string ans;

cin >> a>>b>>c;

if(a==b&&a==c)ans="Yes";
else ans="No";


cout << ans << endl;
return 0;
}



