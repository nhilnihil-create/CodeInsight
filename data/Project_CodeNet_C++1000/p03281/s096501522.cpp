#include <bits/stdc++.h>
#include <algorithm>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;

int main(){
    int n;
    cin >> n;
    int count1 = 0;
    int count2 = 0;
    
    for(int i = 1; i <= n; i++) {
         if(i % 2 != 0){
             count1 = 0;
     for(int j = 1; j <= i; j++){
      if(i % j == 0) {
       count1++;
      }
     } 
     if (count1 == 8) {
         count2++;
     }
         }
    }
    cout << count2;
}