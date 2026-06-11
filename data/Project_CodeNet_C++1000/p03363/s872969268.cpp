#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<long> v(n);
  for(int i=0;i<n;i++){cin >> v.at(i);}
  vector<long> b(n+1,0);
  for(int i=0;i<n;i++){b.at(i+1) = v.at(i)+b.at(i);}

  sort(b.begin(),b.end());
  b.push_back(10000000000);
  vector<long> p;
  long num = 0;

  for(int i=0;i<b.size()-1;i++){
      if(b.at(i)!=b.at(i+1)){
          p.push_back(i+1-num);
          num = i+1;
        }
  }
    long ans = 0;
    for(int i=0;i<p.size();i++){
        ans += (p.at(i)*(p.at(i)-1))/2;
    }
    cout << ans << endl;
    return 0;
}