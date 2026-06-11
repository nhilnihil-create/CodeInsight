#include<bits/stdc++.h>
using namespace std;
int main(){
  int A,B,C,D;cin>>A>>B>>C>>D;
  cout<<(abs(C-B)<=D&&abs(B-A)<=D||abs(C-A)<=D?"Yes":"No")<<endl;
}