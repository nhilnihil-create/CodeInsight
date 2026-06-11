#include <bits/stdc++.h>
using namespace std;

int main() {
  int n,answer;
  cin>>n;
  vector<int> nums(n);
  for(int i=0; i<n; i++){
    cin>>nums.at(i);
  }
  sort(nums.begin(), nums.end());
  reverse(nums.begin(), nums.end());
  answer=nums.at(0);
  for(int i=1; i<n; i++){
    if(i%2==1){
      answer=answer-nums.at(i);
    }else{
      answer=answer+nums.at(i);
    }
  }
  cout<<answer<<endl;
}