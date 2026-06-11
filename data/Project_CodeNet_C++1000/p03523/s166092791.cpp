#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = long long;
#define rep(i,n)  for(ll i=0;i < (ll) (n); ++i)

int main(){
  string s;
  vector<string> j = {"KIHBR","AKIHBR","KIHABR","KIHBAR","KIHBRA",
                      "AKIHABR","AKIHBARA","AKIHBRA",
                      "KIHABAR","KIHABRA","KIHBARA",
                      "AKIHABAR","AKIHABRA","AKIHBARA",
                      "KIHABARA","AKIHABARA"};
  cin >> s;
  if( count(j.begin(),j.end(),s) == 0 ){
    cout << "NO" << endl;
  }else{
    cout << "YES" << endl;
  }
  return 0;
}
