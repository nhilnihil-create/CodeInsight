#include <bits/stdc++.h>
using namespace std;

int main(void){
    
   int a,b,k,min_num;
   cin >> a >> b >> k;
   min_num = min(a,b);
   vector<int> vec{};
   
   for(int i=1;i<=min_num;i++){
       if(a%i == 0 && b%i == 0) vec.push_back(i);
       
   }
   sort(vec.begin(),vec.end(),greater<int>());
   
   cout << vec[k-1] << endl;
}