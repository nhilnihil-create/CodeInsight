#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
   ll n;    cin >> n;
   string s;    cin >> s;
   vector<int> wc(n+1), ec(n+1);
   for(int i=0; i<n; i++)
       if(s[i]=='W'){
           wc.at(i+1) = wc.at(i)+1;
           ec.at(i+1) = ec.at(i);
       }else{
          wc.at(i+1) = wc.at(i);
          ec.at(i+1) = ec.at(i)+1; 
       }
    ll ans = 1e+10;
    for(int i=1; i<=n; i++){
        ll tmp = wc.at(i-1) + ec.at(n)-ec.at(i);
        ans = min(tmp, ans);
    }
    cout << ans << endl;
   
}