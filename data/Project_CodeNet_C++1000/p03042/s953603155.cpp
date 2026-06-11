#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int main(){
  string n;
  cin >> n;
  int ye,mo;
  ye=(n[0]-'0')*10+(n[1]-'0');
  mo=(n[2]-'0')*10+(n[3]-'0');
  if(ye>=1 && ye<=12 && mo>=1 && mo<=12){
    cout << "AMBIGUOUS" << endl;
  }
  else if(ye>=1 && ye<=12){
    cout << "MMYY" << endl;
  }
  else if(mo>=1 && mo<=12){
    cout << "YYMM" << endl;
  }
  else{
    cout << "NA" << endl;
  }
}