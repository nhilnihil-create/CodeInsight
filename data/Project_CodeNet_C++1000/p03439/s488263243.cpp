#include<bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  string STARTRESULT = "WAKARAN";
  string ENDRESULT = "WAKARAN";
  string RESULT = "WAKARAN";
  int startposit = 0;
  int endposit = n-1;
  cout << 0 << endl;
  fflush(stdout);
  cin >> STARTRESULT;
  cout << n-1 << endl;
  fflush(stdout);
  cin >> ENDRESULT;
  for(int COUNT=0;COUNT < 20;COUNT++){
    int mid = (startposit+endposit)/2;
    cout << (startposit+endposit)/2 << endl;
    fflush(stdout);
    cin >> RESULT;
    if(RESULT != "Vacant"){
      if((STARTRESULT == RESULT && (mid-startposit) % 2 == 1)||
         (STARTRESULT != RESULT && (mid-startposit) % 2 == 0)){
        endposit = mid;
        ENDRESULT = RESULT;
      }else{
        startposit = mid;
        STARTRESULT = RESULT;
      }
    }else{
      return 0;
    }
  }
}
         
      
    
    