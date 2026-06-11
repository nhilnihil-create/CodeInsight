#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <algorithm>
#include <set>
#include <iomanip>
#include <stdio.h>
#include <sstream>
#include <bits/stdc++.h>
using namespace std;
int main(void){
  long long int n,m,x,y;
  cin>>n>>m>>x>>y;
  vector<long long int> hoge(n);
  for(long long int i=0; i<n; i++){
    cin>>hoge.at(i);
  }
  vector<long long int> huga(m);
  for(long long int i=0; i<m; i++){
    cin>>huga.at(i);
  }
  sort(hoge.begin(),hoge.end());
  sort(huga.begin(),huga.end());
  long long int rightx=hoge.at(n-1);
  long long int lefty=huga.at(0);
  if(rightx<lefty&&rightx<y&&x<lefty){
    cout<<"No War"<<endl;
  }else{
    cout<<"War"<<endl;
  }
}
