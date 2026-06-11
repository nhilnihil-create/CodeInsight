#include <bits/stdc++.h>

using ll = long long;
using namespace std;
const int INFint = 2e9+1;
const ll INFll = 2e18+1;
ll MOD=1e9+7;


int main() {
  int N;
  cin>>N;
  int left = 0,right = N;
  cout << 0 << endl;
  string hazime;
  cin>>hazime;
  while(right - left > 1){
    int mid = (left + right) / 2;
    cout << mid << endl;
    string s;
    cin>>s;
    if((s != hazime && mid % 2 == 0) || (s == hazime && mid%2 == 1)){
      right = mid;
    }else{
      left = mid;
    }
    //cout << left << " " << right << endl;
  }
  cout << left << endl;
  //for(int i(0);i<20;i++){
    //cout << i << endl;
    //string s;
    //cin>>s;
  //}
  return 0;
}