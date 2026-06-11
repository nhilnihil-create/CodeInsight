#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
typedef vector<int> VI;
ll mm=1000000000;ll MM=mm+7;
#define rep(i, n) for(int i=0;i<n;i++)
#define PI 3.141592653589793

int main(){
    ll n;
    cin >> n;
    vector<string> s(n);
    ll m=0;
    ll a=0;
    ll r=0;
    ll c=0;
    ll h=0;
    rep(i,n){
        cin >> s.at(i);
        if(s.at(i).at(0)=='M')m++;
        else if(s.at(i).at(0)=='A')a++;
        else if(s.at(i).at(0)=='R')r++;
        else if(s.at(i).at(0)=='C')c++;
        else if(s.at(i).at(0)=='H')h++; 
    }
    unsigned long long ans;
     ans=m*a*r+m*a*c+m*a*h+m*r*c+m*r*h+m*c*h+a*r*c+a*r*h+a*c*h+r*c*h;
    cout << ans << endl;
}