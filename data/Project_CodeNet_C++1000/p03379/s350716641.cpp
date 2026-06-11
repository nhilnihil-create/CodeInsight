#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i=0;i < (int)(n);i++)


int main(){
   int n;
   cin >> n;
   vector<int> v(n);
   vector<int> q(n);
   rep(i,n) {
       cin >> v[i];
       q[i] = v[i];
   }
   sort(v.begin(),v.end());
   int x,y;
   x = v[n/2 -1],y = v[n/2];

   for (int i = 0;i < n;i++){
       if (q[i] <= x) cout << y << endl;
       else cout << x << endl;
   }
   return 0;

}