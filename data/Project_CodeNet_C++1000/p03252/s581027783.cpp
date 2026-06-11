#include <iostream>
#include <vector>
#include <string>
#define rep(i,n) for(int i=0; i<(n); ++i)
using namespace std;

vector<char> alps(26,-1), alpt(26,-1); // char - 'a'
string s, t;

int main(){

  cin >> s;
  cin >> t;

  bool ok = true;
  rep(i,s.size()){
    int a = s[i] - 'a';
    int b = t[i] - 'a';

    if(alps[a] != -1 || alpt[b] != -1){
      if(alps[a] != b || alpt[b] != a){
	cout << "No" << endl;
	return 0;
      }
    }
    else{
      alps[a] = b;
      alpt[b] = a;
    }
  }

  cout << "Yes" << endl;

  return 0;
}
