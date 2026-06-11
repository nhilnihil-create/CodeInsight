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
  long long int n,m;
  cin>>n>>m;
  map<long long int,long long int> hoge;
  vector<long long int> a(n);
  queue<long long int> all;
  long long int ans=0;
  for(long long int i=0; i<n; i++){
    cin>>a.at(i);
    ans+=a.at(i);
  }
  vector<pair<long long int,long long int>> b(m);
  for(long long int i=0; i<m; i++){
    cin>>b.at(i).second>>b.at(i).first;
  }

  sort(a.begin(),a.end());
  sort(b.begin(),b.end());
  reverse(b.begin(),b.end());

  for(long long int i=0; i<n; i++){
    if(i==0){
      hoge[a.at(i)]++;
      all.push(a.at(i));
    }else{
      hoge[a.at(i)]++;
      if(a.at(i)!=a.at(i-1)){
        all.push(a.at(i));
      }
    }
  }


  for(long long int i=0; i<m; i++){
    if(all.size()<=0){
      break;
    }
    while(true){
      if(all.size()<=0){
        break;
      }
      long long int low=all.front();
      if(b.at(i).first<=low){
        break;
      }
      if(b.at(i).second>=hoge[low]){
        ans-=hoge[low]*low;
        ans+=hoge[low]*b.at(i).first;
        b.at(i).second-=hoge[low];
        hoge[b.at(i).first]=hoge[low];
        hoge[low]=0;
      }else{
        ans-=low*b.at(i).second;
        ans+=b.at(i).first*b.at(i).second;
        hoge[low]-=b.at(i).second;
        hoge[b.at(i).first]+=b.at(i).second;
        b.at(i).second=0;
      }

      if(b.at(i).second<=0){
        break;
      }
      if(hoge[low]==0){
        all.pop();
      }
    }
  }
  cout<<ans<<endl;
}