#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0;i<int(n);i++)
#define _GLIBCXX_DEBUG


int main(){
   string s;
   cin>>s;
   char j,k,l;
   j=s[0];
   k=s[1];
   l=s[2];
   if (l==k || l==j || j==k) {
       cout<<"No";
   } else {
       cout<<"Yes";
   }
}