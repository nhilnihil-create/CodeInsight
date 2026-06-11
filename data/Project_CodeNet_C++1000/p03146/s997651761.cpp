#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main(void){
   
   int s;
   cin >> s;
   
   set<int> st;
   
   int count = 1;
   
   while(true){
       
       if (st.count(s)){
           cout << count << endl;
           return 0;
       }
       
       st.insert(s);
       
       if (s % 2 == 0){
           s /= 2;
       }else{
           s = 3*s + 1;
       }
       
       count ++;
   }
}
