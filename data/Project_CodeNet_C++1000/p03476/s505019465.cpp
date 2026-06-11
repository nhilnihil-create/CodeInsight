#include <bits/stdc++.h>
using namespace std;
bool IsPrime(int num){
    if (num < 2) return false;
    if (num == 2) return true;
    if (num % 2 == 0) return false; // 偶数はあらかじめ除く
    double sqrtNum = sqrt(num);
    for (int i = 3; i <= sqrtNum; i += 2)if (num % i == 0)return false;
    return true;
}
int main(){
  vector<int>A(100010,0);
  for(int i=3;i<100010;i++){
    A[i]=A[i-1];
    if(IsPrime(i)&&IsPrime((i+1)/2))A[i]++;
  }
  int N;cin>>N;
  for(int i=0;i<N;i++){
    int a,b;cin>>a>>b;
    cout<<A[b]-A[a-1]<<endl;
  }
}