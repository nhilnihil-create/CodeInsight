#include<bits/stdc++.h>
using namespace std;

int main(){
  int A,B,cnt;
  cin >> A >> B;
  cnt=0;
  for(int i=A;i<=B;i++){
    int tmp=i;
    int a,b,c,d,e;
    a=tmp%10; tmp/=10;
    b=tmp%10; tmp/=10;
    c=tmp%10; tmp/=10;
    d=tmp%10; tmp/=10;
    e=tmp%10; tmp/=10;
    if(a==e&&b==d)cnt++;
  }
  cout << cnt << endl;
}