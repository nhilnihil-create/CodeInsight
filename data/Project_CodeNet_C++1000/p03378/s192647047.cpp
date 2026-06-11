#include<bits/stdc++.h>
using namespace std;
int main(){
int n,m,x;
cin >>n>>m>>x;
vector <int>num(n,0);
for(int i=0;i<n;i++){
int l;
cin >>l;
num.at(l-1)=1; 
}
int sum=0;
for(int i=0;i<x-1;i++){
sum += num.at(i);
}
int mi =0;
mi=min(sum,m-sum);
cout << mi <<endl; 
}

