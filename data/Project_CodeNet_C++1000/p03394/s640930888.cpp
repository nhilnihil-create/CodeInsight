#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

int main(){
  int N;cin>>N;
  vi table;
  for (int i=1;i<=15000;++i){table.push_back(2*i);}
  for (int i=0;i<5000;++i){table.push_back(3+6*i);}
  
  if(N==3){cout << 2 <<' ' << 3<< ' ' << 25; return 0;}
  if(N==4){cout << 2 <<' ' << 3<< ' ' << 25<< ' ' << 30; return 0;}
  if(N==6){cout << 2 <<' ' << 3<< ' ' << 25<< ' ' << 30<< ' ' << 60 << ' ' << 90; return 0;}
  if(N<=15000){
    if (N%3==1){
      cout << 3 << ' '<< 9<< ' ' << 15 << ' ' <<21 << ' ';
      for (int i=1;i<=N-4;++i){
        cout << 2*i << ' ';
      }
      return 0;
    }
  
    if(N%3==2){
      cout << 3 << ' ' << 9 << ' ';
      for (int i=1;i<=N-2;++i){
        cout << 2*i << ' ';
      }
      return 0;
    }
    if(N%3==0){
      cout << 3 << ' ' << 9 << ' ' << 15 << ' ' << 21 << ' ' << 27 << ' ' << 33 << ' ';
      for (int i=1;i<=N-6;++i){
        cout << 2*i << ' ';
      }
      return 0;
    }
  }

  if(N%2==0){
    for (int i=0;i<N;++i){
      cout << table[i] << ' ';
    }
    return 0;
  }
  if(N%2==1){
    for (int i=0;i<14999;++i){
      cout << table[i] << ' ';
    }
    for (int i=0;i<N-14999;++i){
      cout << table[15000+i] << ' ';
    }
    return 0;
  }
}
