#include <iostream>
#include <vector>
#include <cstdlib>  
#include <algorithm>
#include <string>

using namespace std;
 
int main() {
    string s;cin>>s;
    int ss = 10000;
    for(int i = 0;i<s.length()-2;i++){
      string a = s.substr(i,3);
      int sa = abs(753 -stoi(a));
      ss = min(ss,sa);
    }
    cout<<ss;
    return 0;
}