#include<bits/stdc++.h>
using namespace std;
int main(){
  int N=0, A=0, B=0;
  int a,b,c,d,e,sum,ans=0;
  cin >> N >> A >> B;
  for(int i=1;i<=N;i++){
    a=i/10000;
    b=i/1000%10;
    c=i/100%10;
    d=i/10%10;
    e=i%10;
    sum=a+b+c+d+e;
    if(sum>=A && sum<=B){
      ans+=i;
    }
  }
  cout << ans << endl;
}