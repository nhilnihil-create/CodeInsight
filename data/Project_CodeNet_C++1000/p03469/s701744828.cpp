#include <iostream>

using namespace std;

int main(){
  string date;
  cin >> date;
  
  size_t strPos = date.find("2017");
  if(strPos != string::npos){
    date.replace(strPos, strPos + 4, "2018");
    cout << date << endl;
  }
  else{
    cout << date << endl;
  }
}