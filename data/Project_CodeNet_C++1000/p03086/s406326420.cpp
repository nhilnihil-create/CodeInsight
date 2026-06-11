#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
using ll=long long;
using namespace std;
int main(){
   string s;
   cin>>s;
   int answer=0;
   int a=0;
   for(int i=0;i<s.size();i++){
       if(s.at(i)=='A' ||s.at(i)=='C' ||s.at(i)=='G'||s.at(i)=='T') {
          a++; 
          answer=max(answer,a);
       }
       else{
          
          a=0;
        } 
   }
   cout<<answer<<endl;
}
