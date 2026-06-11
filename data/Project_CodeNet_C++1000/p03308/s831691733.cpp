#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin >> n;
  vector<int>a(n);
  for(int i=0;i<n;i++){
    cin >> a.at(i);
  }
  int max=a.at(0),min=a.at(0);
  for(int i=1;i<n;i++){
		if(min>a.at(i))
			min=a.at(i);
		if(max<a.at(i))
			max=a.at(i);
  }
  cout << max-min << endl;
}