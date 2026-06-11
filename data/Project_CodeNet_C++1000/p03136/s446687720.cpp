#include<bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<int> l(n);
  int sum = 0;
  for(int i = 0; i < n; i++){
    cin >> l[i];
    sum += l[i];
  }
  if(*max_element(l.begin(),l.end()) < sum - *max_element(l.begin(), l.end())){
    cout << "Yes" << endl;
  }else{
    cout << "No" << endl;
  }
}