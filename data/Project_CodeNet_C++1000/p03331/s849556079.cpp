#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define MOD 1000000007
#define INF 1000000000000000000

int main(){
  string S;
  cin>>S;
  int n=S.size();
  int sum=0;
  for(int i=0;i<n;i++){
    sum+=S.at(i)-'0';
  }
  if(sum==1){
    cout<<10<<endl;
  }else{
    cout<<sum<<endl;
  }
}
