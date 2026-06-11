#include <bits/stdc++.h>
using namespace std;
 
 int main(){
 int n,k;
 int ans = 1;
 cin >> n >> k ;

 for (int i=0; i<n; i++){
 if (ans*2 < ans +k){
     ans =ans *2;
 }
 else {
     ans = ans +k;
 }
 }
 cout << ans << endl;
 }