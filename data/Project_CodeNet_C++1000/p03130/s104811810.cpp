#include<bits/stdc++.h>
using namespace std;
int a[6],ap[4];
int main(){
  for(int i=0;i<6;i++){cin>>a[i];ap[a[i]-1]++;}
  for(int i=0;i<4;i++)if(ap[i]==3){cout<<"NO"<<endl;return 0;}
  cout<<"YES"<<endl;
}
