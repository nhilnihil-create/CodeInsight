#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin >> n;
  int a=0,b=0,c=0,x,y,t;
  for(int i=n;i>0;i--){
    cin>>t>>x>>y;
    if(t-c<abs(a-x)+abs(b-y)||(t-c)%2!=(abs(a-x)+abs(b-y))%2){
      cout << "No";
      return 0;
    }
    a=x;
    b=y;
    c=t;
  }
  cout << "Yes";
}
