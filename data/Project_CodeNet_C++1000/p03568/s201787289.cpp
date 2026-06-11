#include <iostream>
#include <string>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;
using ll = long long;

int main(void){

   int n;
   cin >> n;

   vector<int> a(n);
   for (int i = 0; i < n;i++)
      cin >> a.at(i);

   //すべての可能性
   ll cnt = pow(3, n);

   int d_cnt = 1;
   for (int i = 0; i < n; i++){
      if(a.at(i)%2==0)
         d_cnt *= 2;
   }
   cout << cnt-d_cnt << endl;

   return 0;
   }
