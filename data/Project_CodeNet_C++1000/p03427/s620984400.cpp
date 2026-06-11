#include<bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i,n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(),v.end()
#define INF INT_MAX;
typedef long long ll;
using namespace std;

int main(){
  string n; cin >> n;
  string s=n.substr(0,1);
  bool a = true;
  for(int64_t i=1;i<n.size();i++){
    a = a&&n[i]=='9';
  }
  if((int)n.size()==1){
    cout << n << endl;
    return 0;
  }

  if(a){
    cout << 9*(n.size()-1)+stoi(s) << endl;
  }else{
    if(s=="1") cout << 9*(n.size()-1) << endl;
    else cout << 9*(n.size()-1)+stoi(s)-1;
  }
}