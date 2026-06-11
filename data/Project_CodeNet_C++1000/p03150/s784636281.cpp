#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
#define adrep(i,s,n) for (int i=(s);i<(n);i++)
using namespace std;
typedef long long ll;
int main(){

  string s;
  cin>>s;
  
  string key="keyence";

  if(s==key){cout<<"YES"<<endl;return 0;}
  
  int N=s.size();

  rep(i,N){

    for(int leng=1;leng<N-i+1;leng++){

      //cout<<i<<" "<<leng<<endl;
      string t=s;
      t.erase( t.begin()+i, t.begin()+i+leng);
      if(t==key){cout<<"YES"<<endl;return 0;}
      //cout<<t<<endl;
    }
  }
  
  cout<<"NO"<<endl;
  
}
