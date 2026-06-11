#include<bits/stdc++.h>
using namespace std;

int main(void){
  char S[10];
  int S1, S2, S3;
  scanf("%s", S);
  S1 = (S[0] - 48) * 1000 + (S[1] - 48) * 100 + (S[2] - 48) * 10 + (S[3] - 48);
  if(S[5] == '0')
    S2 = S[6] - 48;
  else
    S2 = (S[5] - 48) * 10 + (S[6] - 48);
  if(S[8] == '0')
    S3 = S[9] - 48;
  else
    S3 = (S[8] - 48) * 10 + (S[9] - 48);
  if(S2 < 4)
    cout << "Heisei" << "\n";
  else if(S2 == 4){
    if(S3 <= 30)
      cout << "Heisei" << "\n";
    else
      cout << "TBD" << "\n";
  }
  else if(S2 > 4)
    cout << "TBD" << "\n";
  return 0;
}
