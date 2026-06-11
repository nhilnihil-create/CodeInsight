#include <bits/stdc++.h>
using namespace std;

int main(){
  int64_t K,MfromC,CfromM; 
  cin >> K >> MfromC >> CfromM;
  
  int64_t Kremain= max(K- (MfromC- 1), (int64_t)0);

  int64_t ans= (Kremain==0)          ? K+1
              :(CfromM- MfromC <= 2) ? K+1
              :(Kremain % 2==1)      ? MfromC+ 1+ (Kremain/2)*(CfromM- MfromC)
                                     : MfromC+    (Kremain/2)*(CfromM- MfromC);

  cout << ans << endl;
}