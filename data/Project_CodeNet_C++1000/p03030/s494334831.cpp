#include<iostream>
#include<stdio.h>
#include<cstring>
#include<cmath>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
#include<unordered_map>
#define ll long long 
#define dd double
using namespace std;
 
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin>>n;
  vector<pair<pair<string,int>,int>> v;
  int i;
  string s;
  int p;
  for(i=0;i<n;i++){
  	cin>>s>>p;
  	v.push_back(make_pair(make_pair(s,-p),i+1));
  	
  }
  
//  cout<<endl;
//  for(i=0;i<n;i++){
//  	cout<<v[i].first.first<<" "<<v[i].first.second<<" "<<v[i].second<<endl;
//  }
  
  sort(v.begin(),v.end());
//  cout<<endl;
//  for(i=0;i<n;i++){
//  	cout<<v[i].first.first<<" "<<v[i].first.second<<" "<<v[i].second<<endl;
//  }
  
//  cout<<endl;
    for(i=0;i<n;i++){
  	cout<<v[i].second<<endl;
  }
  
  return 0;
} 