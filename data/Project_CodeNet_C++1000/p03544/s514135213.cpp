#include <bits/stdc++.h>
using namespace std;
 
int main() {
int N;
int64_t x,y ;
scanf("%d",&N);
x=2;
y=1;
for (int i =2;i<N+1;i++){
swap(x,y);
y=x+y;}
cout<<y<<endl;}
