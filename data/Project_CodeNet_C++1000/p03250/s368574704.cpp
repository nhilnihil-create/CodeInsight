  #include <iostream>
  #include <string>
  #include <vector>
  #include <algorithm>
  #include <utility>
  using namespace std;
  typedef long long ll;
  #define rep(i,n) for (int i=0;i < (int)(n);i++)
  
  
  int main(){
    vector<int> v(3);
    cin >> v[0]>> v[1] >> v[2];
    sort(v.begin(),v.end());
    cout << v[0] + v[1] + v[2]*10<< endl;
    
    return 0;
  }
