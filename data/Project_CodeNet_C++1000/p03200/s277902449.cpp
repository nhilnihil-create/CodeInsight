
#include <bits/stdc++.h>
using namespace std;
 typedef long long ll;
 
int main() {
string s;
cin>>s;
ll lo = s.size()-1;
ll ans = 0;
ll w = 0;
for(int i = 0; i<lo+1;i++){
if(s[i]=='W'){
ans+=i-w;
w++;
}
}
cout<<ans<<endl;
}