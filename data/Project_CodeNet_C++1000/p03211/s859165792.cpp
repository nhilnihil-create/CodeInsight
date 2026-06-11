#include <bits/stdc++.h>
#include <string>
using namespace std;
 
int ctoi(char c) {
	if (c >= '0' && c <= '9') {
		return c - '0';
	}
	return 0;
}

int main() {
  string str;
  cin >> str;
  int x=810;
  
  for(int i=0;i<str.size()-2;i++){
     x=min(x,abs(ctoi(str.at(i))*100+ctoi(str.at(i+1))*10+ctoi(str.at(i+2))-753));
  }

  cout << x <<endl;

}
      