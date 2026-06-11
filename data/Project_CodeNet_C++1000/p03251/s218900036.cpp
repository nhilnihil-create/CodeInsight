  #include <iostream>
  #include <string>
  #include <vector>
  #include <algorithm>
  #include <utility>
  using namespace std;
  typedef long long ll;
  #define rep(i,n) for (int i=0;i < (int)(n);i++)
  
  
  int main(){
    int n,m,x,y;
    cin >> n >> m >> x >> y;
    int mx = -1,my = 1000;
    rep(i,n) {
      int tmp;
      cin >> tmp;
      mx = max(mx,tmp);
    }
    rep(i,m){
      int tmp;
      cin >> tmp;
      my = min(my,tmp);
    }
    for (x = x+1; x <= y; x++){
      if (mx < x && my >= x){
        cout << "No War" << endl;
        return 0;
      }
    }
    cout << "War" << endl;

    
    return 0;
  }
