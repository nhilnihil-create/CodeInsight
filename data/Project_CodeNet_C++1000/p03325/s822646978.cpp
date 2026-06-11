#include <bits/stdc++.h>
using namespace std;
 int main (){
int n;
cin >> n;
 vector<int> a(n);
 int sum=0;
 for(int i=0;i<n;i++){
     cin >> a.at(i);
     while(a.at(i)==(a.at(i)/2)*2){
         a.at(i)=a.at(i)/2;
         sum++;
     }
 }
cout << sum << endl;
 }