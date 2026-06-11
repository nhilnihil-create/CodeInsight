#include <bits/stdc++.h>
using namespace std;

int main(){
int n;
  cin >> n;
string s;
  cin >> s;
vector<int> e(n);  
vector<int> w(n);
for(int i=0;i<n;i++){
if(s[i]=='E')e[i]=1;
if(s[i]=='W')w[i]=1;  
}
int ans=1000000;
vector<int> sume(n+1,0);  
vector<int> sumw(n+1,0); 
for(int i=0;i<n;i++)sume[i+1]=sume[i]+e[i];
for(int i=0;i<n;i++)sumw[i+1]=sumw[i]+w[i]; 
for(int i=0;i<n;i++){
int k=sumw[i]+sume[n]-sume[i+1];
ans=min(k,ans);
}  
cout << ans << endl;  
}
