#include<iostream>
using namespace std;

int age;
int price;

int main(){
  cin >> age >> price;
  if(age > 12){
    cout << price;
  }
  else if(age < 13 && age > 5){
    cout << price/2;
  }
  else{
    cout << "0";
  }
}