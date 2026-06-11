#include<bits/stdc++.h>
using namespace std;
int main() {
   int n,m;
   int l[100005],r[100005];
   cin>>n>>m;
   for(int i=0;i<m;i++){
      cin>>l[i]>>r[i];
   }
   sort(l,l+m);
   sort(r,r+m);
   if(r[0]>=l[m-1]){
     cout<<r[0]-l[m-1]+1<<"\n";
   }
   else{
     cout<<0<<"\n";
   }
   return 0;
}