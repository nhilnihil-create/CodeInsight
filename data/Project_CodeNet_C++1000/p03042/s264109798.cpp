#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
using P=pair<int,int>;
using G=vector<vector<int>>;

string S;

int num, form, latt;

int main(){
  cin >> S;
  num = stoi(S);

  int a, b, c, d;

  a = num / 1000;
  b = (num - a*1000) / 100;
  c = (num - a*1000 - b*100) / 10;
  d = num - a*1000 - b*100 - c*10;

  form = 10*a + b;
  latt = 10*c + d;

  if( form==0 || 13<=form && form<=99){
    if( 1<=latt && latt<=12){
      cout << "YYMM" << endl;
    }else{
      cout << "NA" << endl;
    }
  }else{
    if( latt==0 || 13<=latt && latt<=99 ){
      cout << "MMYY" << endl;
    }else{
      cout << "AMBIGUOUS" << endl;
    }
  }

}
