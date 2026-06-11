#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define rep(i,n) for(int i=0;i<n;i++)
#define INF 999999999
const int mod = 1000000007;
ll cnt = 0;

int main (){
    int a[5];
 for(int i=0;i<5;i++){
     cin >> a[i];
 }

 int n;   cin >> n;
 for(int i=0;i<5;i++){
     for(int j=i+1;j<5;j++){
         if(a[j] - a[i] > n){
             cout << ":(" << endl;
             return 0;
         }
     }
 }

cout << "Yay!" << endl;
  


}