#include <iostream>
#include <vector>
#include <cstdlib>  
#include <algorithm>
#include <string>

using namespace std;
 
int main() {
    string s;cin>>s;
    if(s[0] !='A'){
      cout<<"WA";
      return 0;
    }
    int c = 0;
  	int basyo = 0;
    for(int i = 2;i<=s.length()-2;i++){
       if(s[i] == 'C'){
         c++;
         basyo = i;
       }
    }
    if(c != 1){
      cout<<"WA";
      return 0;
    }
    for(int i = 1;i<s.length();i++){
    	if(i == basyo) continue;
        if(s[i]>='A'&&s[i]<='Z'){
          cout<<"WA";
          return 0;
        }
    }
    cout<<"AC";
    return 0;
}