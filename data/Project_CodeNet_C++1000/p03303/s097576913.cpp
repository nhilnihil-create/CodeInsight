#include<bits/stdc++.h>
#define mins(a,b) a=min(a,b)
#define maxs(a,b) a=max(a,b)
 template < typename T > std::string to_string( const T& n )
  {
    std::ostringstream stm ;
    stm << n ;
    return stm.str() ;
  }
using namespace std;

const long long INF=9000000000000000;
int main(){
  string s;
  int n;
  cin>>s>>n;
  for(int i=0;i<s.size();i+=n){
    cout<<s[i];
  }
  cout<<endl;
}