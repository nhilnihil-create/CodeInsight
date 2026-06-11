#include<bits/stdc++.h>
using namespace std;
#define REP(i,x,n) for(int i=x;i<n;i++)
int main(){
  int n;cin>>n;
  if(n==3) {
    cout<<"2 5 63"<<endl;
    return 0;
  }
  vector<int> numbers;
  REP(i,6,30001) if(i%2==0 || i%3==0) numbers.emplace_back(i);
  while(true){
    vector<int> num = numbers;
    random_shuffle(num.begin(), num.end());
    REP(i,2,5)num.emplace_back(i);
    reverse(num.begin(), num.end());
    long sum=0;
    REP(i,0,n) sum+=num[i];
    if(sum%6==0){
      REP(i,0,n) cout<<num[i]<<" ";
      cout<<endl;
      break;
    }
  }
  return 0;
}