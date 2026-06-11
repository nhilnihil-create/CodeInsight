#include<iostream>
using std::cout;
using std::cin;
using std::endl;

#include<string>
using std::string;

#include<cstdlib>
using std::stoi;

int main()
{
  string s;
  cin >> s;
  
  if (stoi(s.substr(0, 4)) < 2019) cout << "Heisei" << endl;
  else if(stoi(s.substr(5, 2)) < 5) cout << "Heisei" << endl;
  else cout << "TBD" << endl;
  
  return 0;
}
