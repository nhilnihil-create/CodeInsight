#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <map>
using namespace std;
typedef long long ll;
#define rep(i,n) for (int i=0;i < (int)(n);i++)


int main(){
  int n;
  cin >> n;
  char top,end;
  vector<string> strs(n);
  rep(i,n) cin >> strs[i];
  map<string,int> mp;
  
  rep(i,n){
    string tmp = strs[i];
    mp[tmp]++;
    if (i == 0) {
      end = tmp[tmp.size()-1];
      continue;
    }
    else{
      if (mp[tmp] > 1){
        cout << "No" << endl;
        return 0;
      }
      else if (end != tmp[0]){
        cout << "No" << endl;
        return 0;
      }
      else {
        end = tmp[tmp.size()-1];
      }
    }
  }
  cout << "Yes" << endl;
  
  


  return 0; 
}

