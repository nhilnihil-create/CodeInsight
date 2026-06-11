#include <bits/stdc++.h>
using namespace std;

bool done = false;

void calc(int sum, string Sl, string Sr){
  if (!done){
    if (Sr.size() == 1){
      if (sum + stoll(Sr) == 7){
        cout << Sl << "+" << Sr << "=7" << endl;
        done = true;
      } else if (sum - stoll(Sr) == 7){
        cout << Sl << "-" << Sr << "=7" << endl;
        done = true;
      }
    }else{
      if (Sl.size() == 0){
		calc(sum+stoll(Sr.substr(0,1))
             ,Sr.substr(0,1)
             ,Sr.substr(1));
      }else{
        calc(sum+stoll(Sr.substr(0,1))
             ,Sl + "+" + Sr.substr(0,1)
             ,Sr.substr(1));
        calc(sum-stoll(Sr.substr(0,1))
             ,Sl + "-" + Sr.substr(0,1)
             ,Sr.substr(1));
      }
    }
  }
}

int main(){
  string S;
  cin >> S;
//cout << S.size();
  calc(0,"",S);

}