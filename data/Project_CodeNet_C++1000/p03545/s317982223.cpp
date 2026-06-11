#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using P = pair<string,int>;
const double PI = acos(-1);

int main() {
  int y;
  cin >> y;
  vector<int> x(4);
  rep(i,4){
    x.at(i) = y%10;
    y /= 10;
  }
  reverse(x.begin(),x.end());
  if(x.at(0)-x.at(1)-x.at(2)-x.at(3) == 7){
    cout << x.at(0)<<"-"<<x.at(1)<<"-"<<x.at(2)<<"-"<<x.at(3)<<"=7"<< endl;
    return 0;
  }
  if(x.at(0)-x.at(1)-x.at(2)+x.at(3) == 7){
    cout << x.at(0)<<"-"<<x.at(1)<<"-"<<x.at(2)<<"+"<<x.at(3)<<"=7"<< endl;
    return 0;
  }
  if(x.at(0)-x.at(1)+x.at(2)-x.at(3) == 7){
    cout << x.at(0)<<"-"<<x.at(1)<<"+"<<x.at(2)<<"-"<<x.at(3)<<"=7"<< endl;
    return 0;
  }
  if(x.at(0)-x.at(1)+x.at(2)+x.at(3) == 7){
    cout << x.at(0)<<"-"<<x.at(1)<<"+"<<x.at(2)<<"+"<<x.at(3)<<"=7"<< endl;
    return 0;
  }
  if(x.at(0)+x.at(1)-x.at(2)-x.at(3) == 7){
    cout << x.at(0)<<"+"<<x.at(1)<<"-"<<x.at(2)<<"-"<<x.at(3)<<"=7"<< endl;
    return 0;
  }
  if(x.at(0)+x.at(1)-x.at(2)+x.at(3) == 7){
    cout << x.at(0)<<"+"<<x.at(1)<<"-"<<x.at(2)<<"+"<<x.at(3)<<"=7"<< endl;
    return 0;
  }
  if(x.at(0)+x.at(1)+x.at(2)-x.at(3) == 7){
    cout << x.at(0)<<"+"<<x.at(1)<<"+"<<x.at(2)<<"-"<<x.at(3)<<"=7"<< endl;
    return 0;
  }
  if(x.at(0)+x.at(1)+x.at(2)+x.at(3) == 7){
    cout << x.at(0)<<"+"<<x.at(1)<<"+"<<x.at(2)<<"+"<<x.at(3)<<"=7"<< endl;
    return 0;
  }
}
