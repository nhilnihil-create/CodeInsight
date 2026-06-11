#include <bits/stdc++.h>
using namespace std;
 
int main() {
int n;
  cin >>n;
  vector<int> vec(n);
  for(int i=0;i<n;i++)cin>>vec[i];
      sort(vec.begin(), vec.end()); 
    reverse(vec.begin(), vec.end()); 
 int sum=0;
  for(int i=1;i<n;i++){sum += vec[i];}
  if(sum > vec[0])cout<<"Yes"<<endl;
  else cout << "No"<<endl;
}
