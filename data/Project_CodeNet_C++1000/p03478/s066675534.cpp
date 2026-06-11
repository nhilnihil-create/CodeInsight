//つよつよの人のコード
#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,a,b;
  cin>>n>>a>>b;
  int s=0;
  for(int i=1;i<=n;i++){
    int x=i;
    int si=0;
    while(x>0){
      si+=x%10;
      x/=10;
    }
    if(si>=a&&si<=b)
      s+=i;
  }
  cout<<s<<endl;
}
