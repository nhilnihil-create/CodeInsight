#include <bits/stdc++.h>
using namespace std;

int main() {
   int n;
   cin >> n;
   
   vector<int> vec(n);
   
   for (int i=0; i<n; i++) {
       cin >> vec.at(i); 
   }
   
   sort(vec.begin(), vec.end());
   
   int alice = 0;
   int bob = 0;
   
   for (int i=0; i<n; i++) {
       if (i % 2== 0)  alice += vec.at(vec.size()-1);
       else  bob += vec.at(vec.size()-1);
       vec.pop_back();
   }
   
   cout << alice - bob << endl;
   
}