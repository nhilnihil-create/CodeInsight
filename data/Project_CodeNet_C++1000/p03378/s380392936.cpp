#include<bits/stdc++.h>
using namespace std;
int main(){
 int n,m,x;
 cin>>n>>m>>x;
 vector<int> a(m);
 for(int i=0; i<m; i++){
   cin>>a.at(i);
 }
 int right=0,left=0;
 for(int i=0; i<m; i++){
   if(a.at(i)<x) ++left;
   else ++right;
 }
 cout<<min(left,right)<<endl;
}