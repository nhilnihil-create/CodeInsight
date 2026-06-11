#include <bits/stdc++.h>
using namespace std;
 
int main() {
 
  int a,b,c,d,e;
  cin>>a>>b>>c>>d>>e;
  vector<int > vec(5);
  vec[0]=a;vec[1]=b;vec[2]=c;vec[3]=d;vec[4]=e;int k=0;int l=100;
  for(int i=0;i<5;i++){
  if(vec[i]%10 == 0){k += vec[i];}
    else{k+= (vec[i]/10 + 1 ) * 10;
        l =min(l,vec[i]%10);
        }
  }
if(l==100)l=10;  
  cout << k -10 + l <<endl;  
}
