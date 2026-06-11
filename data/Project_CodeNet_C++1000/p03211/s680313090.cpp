#include <bits/stdc++.h>
using namespace std;
const int INF=999999999;

int main() {
 string S;
 cin>>S;

 int ans=INF;
 for(int i=0;i<S.size()-2;i++){
   int a=S.at(i)-'0';
   int b=S.at(i+1)-'0';
   int c=S.at(i+2)-'0';
   int X=100*a+10*b+c;
   ans=min(ans,abs(X-753));
 }
 cout<<ans<<endl;
 return 0;}