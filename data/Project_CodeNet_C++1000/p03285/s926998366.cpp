#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;

int main(){
 int N;
 cin >> N;
 int t = 0;
 for(int i = 0; i < 26; i++){
     for(int j = 0; j < 16; j++){
         if( 4 * i + 7 * j == N){
             t += 1;
             break;
         }
     }
 }
 if(t != 0){
     cout << "Yes" << endl;
 }else{
     cout << "No" << endl;
 }
}