#include <bits/stdc++.h>
using namespace std;

int main(){
   string s;
   cin >> s;
   int count[2]={0,0};
   for(int i=0; i<2; i++){
       for(int j=0; j<s.size(); j++){
//          cout << (s.at(j)-'0'+i+j)%2 << endl;
           if((s.at(j)-'0'+i+j)%2==0) count[i]++;
       }
   }
   cout << min(count[0],count[1]) << endl;
}