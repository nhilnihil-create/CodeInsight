#include<bits/stdc++.h>
 using namespace std;

int main (void){
 int a,b,k;
 cin >> a >> b >> k;

 if(b - a + 1 >= 2*k){
 for(int i = 0;i < k;i++){
 cout << a + i << '\n';
 }
 for(int i = 0;i < k;i++){
 cout << b - k + 1 + i << '\n';
 }
 }else if(b - a + 1 >= k){
 for(int i = 0;i < k;i++){
 cout << a + i << '\n';
 }
 for(int i = 0;i < b - a + 1 - k;i++){
 cout << a + k + i << '\n';
 }
 }else{
 for(int i = 0;i < b - a + 1;i++){
 cout << a + i << '\n';
 }
 }
 return 0;
 }