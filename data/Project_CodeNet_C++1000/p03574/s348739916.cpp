#include <bits/stdc++.h>
using namespace std;
int main(void){
   // Your code here!
   int h, w; cin >> h >> w;
   vector<vector<char>> mas(h+2, vector<char>(w+2));
   
   for(int i = 0; i < h+2; i++){
      if(i==0 || i== h+1){
         for(int j = 0; j < w+2; j++){ mas.at(i).at(j) = '-'; }
      }
      else{
         string line; cin >> line;
         line += "-"; line = "-" + line;
         for(int j = 0; j < w+2; j++){ mas.at(i).at(j) = line.at(j); }
      }
   }
   
   for(int i = 1; i < h+1; i++){
      for(int j = 1; j < w+1; j++){
         if(mas.at(i).at(j) == '.'){
            int count = 0;
            if(mas.at(i-1).at(j-1)=='#')//LU
               count++;
            if(mas.at(i-1).at(j)  =='#')
               count++;
            if(mas.at(i-1).at(j+1)=='#')
               count++;
            if(mas.at(i).at(j-1)  =='#')
               count++;
            if(mas.at(i).at(j+1)  =='#')
               count++;
            if(mas.at(i+1).at(j-1)=='#')
               count++;
            if(mas.at(i+1).at(j)  =='#')
               count++;
            if(mas.at(i+1).at(j+1)=='#')
               count++;
            cout << count;
         }
         else if(mas.at(i).at(j) == '#'){
            cout << "#";
         }
      } cout << endl;
   }
}
