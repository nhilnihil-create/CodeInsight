#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N; 
  cin>>N;
  int res=0;
for(int i=0;i<N;i++){string S;
                    cin>>S;
                    if(S=="Y"){res++;}}
  if(res==0){cout<<"Three"<<endl;}
  else{cout<<"Four"<<endl;}
}
