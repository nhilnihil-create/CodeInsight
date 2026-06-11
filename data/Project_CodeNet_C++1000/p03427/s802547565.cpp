#include <bits/stdc++.h>
using namespace std;
 typedef long long ll;

int main() {
string s;cin>>s;
int lo = s.size();
bool big = 1;
for(int i = 1;i<lo;i++){
    if(s[i]!='9')big = 0;
}
int ans = 0;
if(big==1){
ans = (s[0]-'0')+(lo-1)*9;
}
else{
    ans = (s[0]-'0'-1)+(lo-1)*9;
}
cout<<ans<<endl;
}
