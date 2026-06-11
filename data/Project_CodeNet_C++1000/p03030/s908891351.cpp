#include <bits/stdc++.h>
using namespace std;

int main() {
 int N;
  cin>>N;
  vector< pair< pair<string,int>,int> >a(N);
  for(int i=0;i<N;i++){
	cin>>a.at(i).first.first>>a.at(i).first.second;
    a.at(i).second=i+1;
    a.at(i).first.second *=-1;
  }
  sort(a.begin(),a.end());
  for(int i=0;i<N;i++){
  cout<<a.at(i).second<<endl;
  }
}