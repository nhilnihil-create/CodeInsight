#include <bits/stdc++.h>
using namespace std;

int main() {
  int A,B,C;
  cin >> A >> B >> C;
  vector<int>data(3);
  data.at(0)=A;
  data.at(1)=B;
  data.at(2)=C;
  sort(data.begin(),data.end());
  if((data.at(0)+data.at(1))%2!=0){
    cout << ((data.at(2)+1)*2-data.at(1)-data.at(0)+1)/2 << endl;
  }
  else{
    cout << (data.at(2)*2-data.at(1)-data.at(0))/2 << endl;
  }
}
