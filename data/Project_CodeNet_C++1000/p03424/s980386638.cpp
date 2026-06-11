#include <iostream>
#include <string>
using namespace std;

int main(){
 	int number;
	cin >> number;
	char color[number];
  	for(int i = 0; i < number; ++i){
    	cin >> color[i];
    }
  
	string ans = "Three";
   	for(int i = 0; i < number; ++i){
    	if('Y' == color[i]){
        	ans = "Four";
    	}
    }
  	cout << ans << endl;
  	return 0;
}
