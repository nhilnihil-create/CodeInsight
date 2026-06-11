#include<iostream>
#include<string>
using namespace std;

int main(){
	string s,t;
	cin >> s >> t;
  s= s+s;
  if(s.find(t) != string::npos){
    cout << "Yes";
  }else{
    cout << "No";
  }
}