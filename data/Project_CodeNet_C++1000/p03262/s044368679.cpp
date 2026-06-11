#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b)
{
   if (a%b == 0)
   {
       return(b);
   }
   else
   {
       return(gcd(b, a%b));
   }
}

int lcm(int a, int b)
{
   return a * b / gcd(a, b);
}


int main() {
  int N,X;
  cin>>N>>X;
  vector<int> vec(N);
  for(int i=0;i<N;i++){
    cin>>vec.at(i);
  }
  vector<int> S(N);
  for(int i=0;i<N;i++){
    S.at(i)=abs(vec.at(i)-X);
  }
  if(N==1) cout<<S.at(0)<<endl;
  else{
    int a=gcd(S.at(0),S.at(1));
    for(int i=2;i<N;i++){
      a=gcd(a,S.at(i));
    }
    cout<<a<<endl;
  }
            
    
  
    
  
}
