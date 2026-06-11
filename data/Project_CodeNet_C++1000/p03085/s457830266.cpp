#include <iostream>
using namespace std;
int main(){
  char s;                                                                      cin >> s;
  if(s=='A') cout << 'T' << "\n";                                              else if(s=='T') cout << 'A' << "\n";                                         else if(s=='C') cout << 'G' << "\n";                                         else if(s=='G') cout << 'C' << "\n";                                         return 0;                                                                  }