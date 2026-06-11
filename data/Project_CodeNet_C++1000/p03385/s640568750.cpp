#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector<int> VI;
ll mm=1000000000;ll MM=mm+7;
#define rep(i, n) for(int i=0;i<n;i++)

int main(){
 vector<char> w(3);
  
  cin >> w.at(0) >> w.at(1) >>w.at(2);
 sort(w.begin(),w.end());
  bool a=true;
  if(w.at(0)!='a')a=false;
   if(w.at(1)!='b')a=false;
   if(w.at(2)!='c')a=false;
  if(a)cout << "Yes" << endl;
  else cout << "No" << endl;
}