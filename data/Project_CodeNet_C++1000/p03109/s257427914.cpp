#include <bits/stdc++.h>

using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define ll long long int

int main(){
  int A,B,C;
  char a,b;
  cin>>A>>a>>B>>b>>C;
  if(A<2019)
    cout<<"Heisei"<<endl;
  else if(A==2019&&B<4)
    cout<<"Heisei"<<endl;
  else if(A==2019&&B==4&&C<=30)
    cout<<"Heisei"<<endl;
  else
    cout<<"TBD"<<endl;



  return 0;
}
