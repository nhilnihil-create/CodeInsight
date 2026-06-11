#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main(){
  vector<int> B={2,5,5,4,5,6,3,7,6};
  int C[9]={0,0,0,0,0,0,0,0,0};
  int N, M;
  cin >> N >> M;
  for(int i=0; i<M; i++){
    int num;
    cin >> num;
    if(num==1) C[0]=num;
    if(num==7) C[1]=num;
    if(num==4) C[2]=num;
    if(num==5) C[3]=num;
    if(num==3) C[4]=num;
    if(num==2) C[5]=num;
    if(num==9) C[6]=num;
    if(num==6) C[7]=num;
    if(num==8) C[8]=num;
  }

  int basenum;
  int matchnum;
  for(int i=0; i<9; i++){
    if(C[i]!=0){
      basenum=C[i];
      matchnum=B.at(basenum-1);
      break;
    }
  }
  string ans;
  for(int i=0; i<N/matchnum; i++){
    ans+=basenum +'0';
  }
 
  int moda = N % matchnum;

  if(basenum==1){
    if(moda==1){
      if(C[1]==7) ans.at(0)='7';
      else if(C[3]==5){
        ans.erase(ans.begin());
        ans.at(0)='5';
      }
      else if(C[4]==3){
        ans.erase(ans.begin());
        ans.at(0)='3';
      }
      else if(C[5]==2){
        ans.erase(ans.begin());
        ans.at(0)='2';
      }
      else if(C[8]==8){
        ans.erase(ans.begin());
        ans.erase(ans.begin());
        ans.at(0)='8';
      }
    }
  }

  if(basenum==7){
    if(moda==1){
      if(C[2]==4) ans.at(ans.size()-1)='4';
      else if(C[8]==8){
        ans.erase(ans.begin());
        ans.at(0)='8';
      }
      else if(C[3]==5){
        ans.erase(ans.begin());
        ans.erase(ans.begin());
        ans.at(ans.size()-1)='5';
        ans.at(ans.size()-2)='5';
        ans.at(ans.size()-3)='5';
      }
      else if(C[4]==3){
        ans.erase(ans.begin());
        ans.erase(ans.begin());
        ans.at(ans.size()-1)='3';
        ans.at(ans.size()-2)='3';
        ans.at(ans.size()-3)='3';
      }
      else if(C[5]==2){
        ans.erase(ans.begin());
        ans.erase(ans.begin());
        ans.at(ans.size()-1)='2';
        ans.at(ans.size()-2)='2';
        ans.at(ans.size()-3)='2';
      }
    }
    if(moda==2){
      if(C[3]==5) ans.at(ans.size()-1)='5';
      else if(C[4]==3) ans.at(ans.size()-1)='3';
      else if(C[5]==2) ans.at(ans.size()-1)='2';
      else if(C[2]==4){
        ans.at(ans.size()-1)='4';
        ans.at(ans.size()-2)='4'; 
      }
      else if(C[8]==8){
        ans.erase(ans.begin(),ans.begin()+4);
        ans.at(0)='8';
        ans.at(1)='8';
        ans.at(2)='8';
        ans.at(3)='8';
      }
    }
  }

  if(basenum==4){
    if(moda==1){
      if(C[3]==5) ans.at(0)='5';
      else if(C[4]==3) ans.at(ans.size()-1)='3';
      else if(C[5]==2) ans.at(ans.size()-1)='2';
      else if(C[6]==9 && C[8]==8){
        ans.erase(ans.begin());
        ans.at(0)='9';
        ans.at(1)='8';
      }
      else if(C[7]==6 && C[8]==8){
        ans.erase(ans.begin());
        ans.at(0)='8';
        ans.at(1)='6';
      }
      else if(C[6]==0 && C[7]==0 && C[8]==8){
        ans.erase(ans.begin());
        ans.erase(ans.begin());
        ans.at(0)='8';
        ans.at(1)='8';
        ans.at(2)='8';
      }
    }
    if(moda==2){
      if(C[6]==9) ans.at(0)='9';
      else if(C[7]==6) ans.at(0)='6';
      else if(C[3]==5){
          ans.at(0)='5';
          ans.at(1)='5';
      }
      else if(C[4]==3){
        ans.at(ans.size()-1)='3';
        ans.at(ans.size()-2)='3';
      }
      else if(C[5]==2){
        ans.at(ans.size()-1)='2';
        ans.at(ans.size()-2)='2';
      }
      else if(C[8]==8){
        ans.erase(ans.begin());
        ans.at(0)='8';
        ans.at(1)='8';
      }
    }
    if(moda==3){
      if(C[6]==9 && C[3]==5){
        ans.at(0)='9';
        ans.at(1)='5';
      }
      else if(C[6]==9 && C[4]==3){
        ans.at(0)='9';
        ans.at(ans.size()-1)='3';
      }
      else if(C[6]==9 && C[5]==2){
        ans.at(0)='9';
        ans.at(ans.size()-1)='2';
      }
      else if(C[8]==8){
        ans.at(0)='8';
      }
      else if(C[7]==6){
        ans.at(0)='6';
        if(C[3]==5) ans.at(1)='5';
        else if(C[4]==3) ans.at(ans.size()-1)='3';
        else if(C[5]==2) ans.at(ans.size()-1)='2';
      }
      else if(C[3]==5){
        ans.at(0)='5';
        ans.at(1)='5';
        ans.at(2)='5';
      }
      else if(C[4]==3){
        ans.at(ans.size()-1)='3';
        ans.at(ans.size()-2)='3';
        ans.at(ans.size()-3)='3';
      }
      else if(C[5]==2){
        ans.at(ans.size()-1)='2';
        ans.at(ans.size()-2)='2';
        ans.at(ans.size()-3)='2';
      }
    }
  }

  if(basenum==5 || basenum==3 || basenum==2){
    if(moda==1){
      if(C[6]==9) ans.at(0)='9';
      else if(C[7]==6) ans.at(0)='6';
      else if(C[8]==8){
        ans.erase(ans.begin());
        ans.at(0)='8';
        ans.at(1)='8';
        ans.at(2)='8';
      }
    }
    if(moda==2){
      if(C[6]==9){
        if(ans.size()>=2){
          ans.at(0)='9';
          ans.at(1)='9';
        }
        else if(ans.size()==1 && C[8]==8) ans='8';
      }
      else if(C[8]==8){
        ans.at(0)=='8';
      }
      else if(C[7]==6){
        ans.at(0)='6';
        ans.at(1)='6';
      }
    }
    if(moda==3){
      if(C[6]==9){
        if(ans.size()>=3){
          ans.at(0)='9';
          ans.at(1)='9';
          ans.at(2)='9';
        }
        else if(ans.size()<3 && C[8]==8){
          ans.at(0)='9';
          ans.at(1)='8';
        }
      }
      else if(C[8]==8 && C[7]==6){
        ans.at(0)='8';
        ans.at(1)='6';
      }
      else if(C[7]==6 && C[8]!=8){
        ans.at(0)='6';
        ans.at(1)='6';
        ans.at(2)='6';
      }
      else if(C[8]==8 && C[7]!=6){
        ans.erase(ans.begin());
        ans.at(0)='8';
        ans.at(1)='8';
        ans.at(2)='8';
        ans.at(3)='8';
      }
    }
    if(moda==4){
      if(C[6]==9){
        if(ans.size()>=4){
          ans.at(0)='9';
          ans.at(1)='9';
          ans.at(2)='9';
          ans.at(3)='9';
        }
        else if(ans.size()==3 && C[8]==8){
          ans.at(0)='9';
          ans.at(1)='9';
          ans.at(2)='8';
        }
        else if(ans.size()==2 && C[8]==8){
          ans.at(0)='8';
          ans.at(1)='8';
        }
      }
      else if(C[8]==8){
        ans.at(0)='8';
        ans.at(1)='8';
      }
      else if(C[7]==6){
        ans.at(0)='6';
        ans.at(1)='6';
        ans.at(2)='6';
        ans.at(3)='6';
      }
    }
  }

  if(basenum==6){
    if(moda!=0 && C[8]==8){
      for(int i=0; i<moda; i++){
        ans.at(i)='8';
      }
    }
  }

  if(basenum==9){
    if(moda!=0 && C[8]==8){
      for(int i=0; i<moda; i++){
        ans.at(ans.size()-1-i)='8';
      }
    }
  }
  cout << ans << endl;
}