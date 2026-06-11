#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector<int> VI;
ll mm=1000000000;ll MM=mm+7;
#define rep(i, n) for(int i=0;i<n;i++)

int main(){
 string s;
  cin >> s;
  int n=0;
  rep(i,3){
    if(s.at(i)=='o')n++;
  }
  cout << 700+n*100 << endl;
  
      
}