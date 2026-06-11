 #include<bits/stdc++.h>
using namespace std;
int main(){
  int a,b,c,k;
  cin>>a>>b>>c>>k;
  if(abs(a-b)<=k&&abs(b-c)<=k||abs(a-c)<=k)
    cout<<"Yes"<<endl;
  else
    cout<<"No"<<endl;
  }
