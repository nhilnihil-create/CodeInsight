#include<bits/stdc++.h>
using namespace std;
int main(){
 int n,m,x;
 cin>>n>>m>>x;
 vector<int> a(m);
 for(int i=0; i<m; i++){
   cin>>a.at(i);
 }
 vector<int> road(n+1,0);

for(int i=0; i<m; i++){
  road.at(a.at(i))=1;
}

int cnt1=0,cnt2=0;
for(int i=x; i<=n; i++){
  if(road.at(i)==1) cnt1++;
}
for(int i=x; i>=0; i--){
  if(road.at(i)==1) cnt2++;
}
int ans=min(cnt1,cnt2);
cout<<ans<<endl;
}