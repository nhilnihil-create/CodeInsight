#include <bits/stdc++.h>
using namespace std;

int first_num(int d,long long N){
  for(int i=0;i<d-1;i++){
    N/=10LL;
  }
  return (int)N;
}

int ans_n(int d,long long N){
  int ret=0;
  for(int i=0;i<d;i++){
    ret+=(int)(N%10LL);
    N/=10LL;
  }
  return ret;
}

int main() {
  long long N;
  cin>>N;
  //Nを文字列としたもの
  string sn = to_string(N);
  //Nの桁数
  int digit = sn.size();
  //Nの最高位の数
  int first_n = first_num(digit,N);
  
  int ans_a = (digit-1)*9+(first_n-1);
  int ans_b = ans_n(digit,N);
  cout<<max(ans_a,ans_b)<<endl;
}
