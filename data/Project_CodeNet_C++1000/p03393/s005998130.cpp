#include <iostream>
#include <vector>
#include <utility>
#include <set>
using namespace std;
int main(){
  	string s;
  	cin >> s;
  	if(s.length() == 26){
		set<char> al;
      	char bef = 0;
      for(int i = s.length() - 1; 0 <= i; i--){
		if(bef < s[i]){
          	bef = s[i];
        	al.insert(s[i]);
        }
        else{
			cout << string(s.begin(), s.begin() + i) << *al.lower_bound(s[i]) << endl;
        	return 0;
        }
       }
      	cout << -1 << endl;
    }
  else{
	set<char> al;
    for(char ch = 'a'; 'z' >= ch; ch++) al.insert(ch);
    for(auto ch : s) al.erase(ch);
    cout << s << *al.begin() << endl;
  }
	return 0;
}