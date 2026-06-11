#include <bits/stdc++.h>
#include <algorithm>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;

int main() {
 int n;
 string s;
 
 cin >> n >> s;
 int maxnum = 0;
 
 
 for(int i = 1; i < n; i++) {
     int count = 0;
     
     for(char c = 'a'; c <= 'z'; c++) {
      bool left = false,right = false;
       for(int j = 0; j < i; j++) 
           
        if(s[j] == c) {
         left = true;
        }
         
           for(int j = i; j < n; j++)
        if(s[j] == c){
         right = true;
        }
         
         if(left && right) {
          count++;
         }
         if(maxnum < count) {
         maxnum = count;
         }
     }
 }
  cout << maxnum;
}