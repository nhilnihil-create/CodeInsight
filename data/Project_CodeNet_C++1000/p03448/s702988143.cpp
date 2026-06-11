#include <iostream>

using namespace std;

int get_pattern(int A,int B,int C,int X);

int main(){
int A,B,C,X,ans;
// 入力
// cout << "input A\n";
cin >> A;
// cout << "input B\n";
cin >> B;
// cout << "input C\n";
cin >> C;
// cout << "input X\n";
cin >> X;

try{
    if((A < 0 || A > 50) \
    || (B < 0 || B > 50) \
    || (C < 0 || C > 50) \
    || (X < 50 || X > 20000) \
    || (A+B+C <1) \
    || (X%50 != 0))
    throw "input error";
  }

catch(const char* err){
  cout << "エラー:" << err << '\n';
  return 1;
  }

ans=get_pattern(A,B,C,X);
cout << ans << endl;

return 0;
}


int get_pattern(int A,int B,int C,int X)
{
  int re500,re100,i,j,k,count,temp1,temp2;

  temp1 = temp2 = count = 0;
  re500 = min(X/500,A) + 1;

  for(i=0; i<re500; i++){
    temp1 = X - 500*i;
    re100 = min(temp1/100,B) + 1;
    for(j=0; j<re100; j++){
      temp2 = temp1 - 100*j;
      if((temp2%50==0) && (temp2/50<=C))
        count++;
    }
  }
  return count;
}
