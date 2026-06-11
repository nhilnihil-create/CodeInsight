#include<iostream>
using namespace std;

int main(){
  string s1, s2;
  cin >> s1 >> s2;
  cout<<(s1[0]==s2[2]&&s1[1]==s2[1]&&s1[2]==s2[0] ? "YES" : "NO")<<endl;
  return 0;
}
