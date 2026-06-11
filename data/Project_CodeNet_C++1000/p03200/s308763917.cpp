#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
#include <cstring>
#include <iomanip>
#include <cassert>

using namespace std;
typedef long long ll;

int main(){
   string S;
   cin >> S;
   int size = S.size();
   long long ans = 0;
   int cnt = 0;
   for(int i = size-1;i>=0;i--){
      if(S[i]=='W'){
         cnt++;
      }
      else{
         ans += cnt;
      }
   }
   cout << ans << endl;
   return 0;
}
