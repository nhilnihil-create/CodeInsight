#include <bits/stdc++.h>
using namespace std;

int keta_sum(string C){
  int sum=0;
  for(int i=0;i<C.size();i++){
    int c=C[i] - '0';
    sum +=c;
  }
  return sum;
}

int main(){
  int N,a,b;
  cin >>N;
  int sum;
  int result=10000;
  for(int i=1;i<N/2+1;i++){
    a=i;
    b=N-a;
    string A=to_string(a);
    string B=to_string(b);
    sum=keta_sum(A)+keta_sum(B);
    if(result>=sum){
      result=sum;
    }
  }
  cout << result << endl;
}