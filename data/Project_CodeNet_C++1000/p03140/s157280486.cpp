#include <bits/stdc++.h>
#define r(i,n) for(int i = 0; i<n; i++)
using namespace std;

int main(){
  int n;
  cin >> n;
  string a,b,c;
  cin >> a >> b >> c;
  int count=0,count1=0;
  r(i,n){
    if(a.at(i)==b.at(i)&&b.at(i)==c.at(i))count1=0;
    else if(a.at(i)!=b.at(i)&&b.at(i)!=c.at(i)&&a.at(i)!=c.at(i))count+=2;
    else count++;
  }
  cout << count << endl;
}