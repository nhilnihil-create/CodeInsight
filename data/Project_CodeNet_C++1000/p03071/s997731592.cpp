#include <iostream>
using namespace std;

int main() {
 int s,b,c;
 cin>>s>>b;

  if(s>=b){
	  c=s;
  s=s-1;}


else if(b>=s){
	  c=b;
  b=b-1;}



  if(s>=b){
	  cout<<c+s;}

  if(b>s){
	cout<<c+b;}


	return 0;
}
