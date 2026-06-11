#include <bits/stdc++.h>
using namespace std;
 typedef long long ll;
 
int main() {
string s;
cin>>s;
int l=s.size();
string ans="NO";
for(int i=0;i<l;i++){
    for(int j=0;j<l-i;j++){
        string c=s;
        c.erase(i,j);
if(c=="keyence")ans="YES";
    }
}
cout<<ans<<endl;
}
