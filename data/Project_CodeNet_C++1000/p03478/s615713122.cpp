#include <iostream>
using namespace std;

bool is_sum(const int n,const int a,const int b){
   int mod_val,sum_val,num;
   num = n;
   sum_val = 0;
   while(num){
      mod_val = num % 10;
      sum_val += mod_val;
      num /= 10;
   }
   if(a <= sum_val && sum_val <= b){
      return true;
   }
   return false;
}

int main(int argc, char const *argv[]){
   int N,A,B;
   long long result;
   cin >> N >> A >> B;
   result = 0;
   for(int i = 1;i <= N;i++){
      if(is_sum(i,A,B)){
         result+=i;
      }
   }
   cout << result << endl;
   return 0;
}