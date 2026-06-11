#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
  ll n,m=0,a=0,r=0,c=0,h=0,i;
  cin >> n;
  vector<string> s(n);
  for(i=0;i<n;i++){
    cin >> s.at(i);
    if(s.at(i).at(0)=='M'){
      m++;
    }else if(s.at(i).at(0)=='A'){
      a++;
    }else if(s.at(i).at(0)=='R'){
      r++;
    }else if(s.at(i).at(0)=='C'){
      c++;
    }else if(s.at(i).at(0)=='H'){
      h++;
    }
  }
  
  cout << m*a*r+m*a*c+m*a*h+m*r*c+m*r*h+m*c*h+a*r*c+a*r*h+a*c*h+r*c*h << endl;
}