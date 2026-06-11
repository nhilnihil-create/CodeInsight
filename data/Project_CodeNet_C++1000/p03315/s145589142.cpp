#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<set>
#include<iomanip>
#define pi 3.14159265358979323846
#define ll long long
#define rep(i, a, n) for(int i = a; i < n; i++)
using namespace std;
int main(){
  string s;
  cin >> s;
  int n = s.size(), a = 0;
  rep(i, 0, n){
    if(s[i] == '+'){
      a++;
    }
    else if(s[i] == '-'){
      a--;
    }
  }
  
  cout << a << "\n";
}
  
  
  