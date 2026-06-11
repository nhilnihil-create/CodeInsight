#include <bits/stdc++.h>
using namespace std;
 typedef long long ll;
 
int main() {
int n;
cin>>n;
map<int ,int> d;
for(int i=0;i<n;i++){
int l;
cin>>l;
d[l]++;
}

int m;
cin>>m;
string ans="YES";
for(int i=0;i<m;i++){
int l;
cin>>l;
if(d.count(l) && d.at(l)!=0)d[l]--;
else ans="NO";
}
cout<<ans<<endl;
}