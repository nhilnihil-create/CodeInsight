#include <bits/stdc++.h>
using namespace std;

int main() {  
 vector<int> arr;
 int s; cin >> s;
 arr.push_back(s);
	
  int previous = s;
  bool frag = true;
  while(frag) {
    int current;
    if(previous % 2 == 0) {
  		current = previous / 2;    
    } else {
    	current = previous * 3 + 1;
    }
    for(int i = 0; i < arr.size(); i++) {
      if(arr.at(i) == current) {
        frag = false;
        break;
      }
    }
    arr.push_back(current);
    previous = current;
  }
  cout << arr.size() << endl;

 return 0; 
}