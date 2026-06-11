#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <functional>
using namespace std;
const int MOD = 1e9+7;
using ll = long long;
using vi = vector<int>;
#define rep(i, n) for (int i = 0; i < n; i++)
#define ALL(x) x.begin(), x.end()
int main() {
   string s,t;
   cin >> s >> t;
   sort(ALL(s));
   sort(ALL(t),greater<int>());
   int a = s.size(),b=t.size();
   int c = min(a,b);
   rep(i,c){
     if(s.at(i)!=t.at(i)){
       if(s.at(i)-t.at(i)>0) cout << "No";
       else cout << "Yes";
       return 0;
     }
   }
   if(a<b) cout << "Yes";
   else cout << "No";
   return 0;
}  