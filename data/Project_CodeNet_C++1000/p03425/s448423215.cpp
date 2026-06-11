#include <bits/stdc++.h>
using namespace std;
 
int main(){
  int n;
  cin >> n;
  vector<long long>a(5,0);
  for(int i=0;i<n;i++){
    string s;
    cin >> s;
    if(s.at(0)=='M'){
      a.at(0)++;
    }
    if(s.at(0)=='A'){
      a.at(1)++;
    }
    if(s.at(0)=='R'){
      a.at(2)++;
    }
    if(s.at(0)=='C'){
      a.at(3)++;
    }
    if(s.at(0)=='H'){
      a.at(4)++;
    }
  }
  long long ans=0;
  ans+=(a.at(0)*a.at(1)*(a.at(2)+a.at(3)+a.at(4)));
  ans+=(a.at(0)*a.at(2)*(a.at(3)+a.at(4)));
  ans+=(a.at(1)*a.at(2)*(a.at(3)+a.at(4)));
  ans+=(a.at(4)*a.at(3)*(a.at(0)+a.at(1)+a.at(2)));
  cout << ans << endl;
}
