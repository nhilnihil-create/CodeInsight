#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <numeric>
using namespace std;
typedef long long ll;

int main(){
    ll n,k;cin>>n>>k;
    ll ans=0;
   ll a=n/k,b=n/(k/2)-n/k;
   ans+=a*a*a;
   if(k%2==0)ans+=b*b*b;
cout<<ans;
}