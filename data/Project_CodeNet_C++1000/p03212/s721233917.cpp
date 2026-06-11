#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

ll dfs(ll k,ll n,ll bits){
      if(k > n) return 0;
      ll ret = bits == 7 ? 1 : 0;
      for(int i = 0;i < 3;i++){
            ret += dfs(k * 10 + vector<int>{3,5,7}[i],n,1 << i | bits);

      }
      return ret;
}

int main(){
      ll n;
      cin >> n;
      cout << dfs(0,n,0) << endl;
      return 0;
}
