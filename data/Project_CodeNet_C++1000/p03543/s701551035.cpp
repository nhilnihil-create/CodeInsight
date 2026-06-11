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
  if(s[0] == s[1] && s[1] == s[2]){
    cout << "Yes\n";
    return 0;
  }
  if(s[1] == s[2] && s[2] == s[3]){
    cout << "Yes\n";
    return 0;
  }
  cout << "No\n";
}