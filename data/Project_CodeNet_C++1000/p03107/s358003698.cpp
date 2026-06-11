#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){

   string S; cin >> S;
   int num_zero = 0,num_one = 0;
   int len = S.size();
   for(int i=0;i<len;i++){
       if(S[i] == '0') num_zero++;
       else num_one++;
   }
   cout << 2 * min(num_one,num_zero) << endl;
}