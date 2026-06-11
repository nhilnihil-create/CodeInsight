#include<iostream>
#include<vector>
#define P pair<int, int>

using namespace std;

int main(){
  int n;
  cin >> n;
  vector<P> v;
  for(int i=1;i<=n;i++){
  	for(int j=i+1;j<=n;j++){
    	if(i+j!=n/2*2+1)v.push_back(P(i,j));
    }
  }
  cout << v.size() << endl;
  for(int i=0;i<v.size();i++){
  	cout << v[i].first << ' ' << v[i].second << endl;
  }
}