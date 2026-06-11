#include <bits/stdc++.h>
using namespace std;

int main(void){
   
   int N;
   char s;
   map<char,int> mp{};
   cin >> N;
   
   for(int i=0;i<N;i++){
       cin >> s;
       mp[s] = 1;
   }
   
   if(mp.size() == 4){
       cout << "Four" << endl;
   }
   else if(mp.size() == 3){
       cout << "Three" << endl;
   }
}