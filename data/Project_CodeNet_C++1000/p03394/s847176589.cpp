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
   int N;
   cin >> N;
   vector<int> ans;
   if(N==3){
      cout << "2 5 63" << endl;
      return 0;
   }
   ll sum = 0;
   for(int j = 1; j <= N; j++){
      ans.push_back(2*j);
      sum += 2*j;
      if((N-j)%2==0 && N-j <= 5000 && sum%3==0){
         N-=j;
         break;
      } 
   }
   int t = 3;
   for(int j = 0 ; j < N; j++){
      ans.push_back(t);
      t+=6;
   }
   sort(ans.begin(),ans.end());
   for(int a: ans ) cout << a << " ";
   cout << endl;
   return 0;
}
