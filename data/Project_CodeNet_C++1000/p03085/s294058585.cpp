#include <iostream>
using namespace std;
int main(){
  char b;
  cin >> b;
  switch(b)
  {
    case 'A':cout << 'T';break;
    case 'C':cout << 'G';break;
    case 'G':cout << 'C';break;
    case 'T':cout << 'A';break;
  }
}