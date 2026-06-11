#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define MOD 1000000007
#define INF 800000000
#define MAX 1000

int main(){
  string s;
  cin>>s;
  int n=s.size();

  bool flag=true;
  int count=0;
  int left=0;
  int right=n-1;
  while(left<=right){
    if(s.at(left)==s.at(right)){
      left++;
      right--;
    }else if(s.at(left)=='x'){
      count++;
      left++;
    }else if(s.at(right)=='x'){
      count++;
      right--;
    }else{
      flag=false;
      break;
    }
  }
  if(flag){
    cout<<count<<endl;
  }else{
    cout<<-1<<endl;
  }
}
