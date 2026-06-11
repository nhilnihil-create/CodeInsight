#include <bits/stdc++.h>
using namespace std;
int main() {
  int s; cin>>s;
  int a[4]={s/1000,s/100%10,s/10%10,s%10};
  for(int p=0;p<1<<3;p++){
    int s=a[0];
    char op[3];
    for(int b=0;b<3;b++){
      if(p&1<<b) s+=a[b+1],op[b]='+';
      else s-=a[b+1],op[b]='-';
    }
    if(s==7){
      cout<<a[0]<<op[0]<<a[1]<<op[1]<<a[2]<<op[2]<<a[3]<<"=7"<<endl;
      return 0;
    }
  }
}

