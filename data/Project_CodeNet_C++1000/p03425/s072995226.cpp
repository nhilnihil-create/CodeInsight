#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int n;
    cin >> n;
    ll m=0,a=0,r=0,c=0,h=0;
    for(int i=0; i<n; i++){
        string s;
        cin >> s;
        if(s.at(0) == 'M') m++;
        if(s.at(0) == 'A') a++;
        if(s.at(0) == 'R') r++;
        if(s.at(0) == 'C') c++;
        if(s.at(0) == 'H') h++;
    }
    ll ans=0;
    ans += m*a*r + m*a*c + m*a*h;
    ans += m*r*c + m*r*h + m*c*h;
    ans += a*r*c + a*r*h + a*c*h + r*c*h;
    cout << ans << endl;
}