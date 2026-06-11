#include <bits/stdc++.h>
using namespace std;
int sum(int a){
return a*(a+1)/2;}

int main(){
int a,b; cin>>a>>b;
  cout<<sum(b-a)-b<<endl;
}