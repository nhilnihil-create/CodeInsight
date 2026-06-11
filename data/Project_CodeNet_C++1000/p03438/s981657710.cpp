#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define MOD 1000000007

int main(){
  int N;
  cin>>N;
  vector<ll> a(N),b(N);
  for(int i=0;i<N;i++){
    cin>>a.at(i);
  }
  for(int i=0;i<N;i++){
    cin>>b.at(i);
  }

  ll a_count=0,b_count=0;
  for(int i=0;i<N;i++){
    if(a.at(i)>b.at(i)){
      b_count+=a.at(i)-b.at(i);
    }else{
      if((b.at(i)-a.at(i))%2==0){
        a_count+=(b.at(i)-a.at(i))/2;
      }else{
        a_count+=(b.at(i)-a.at(i)-1)/2+1;
        b_count++;
      }
    }
  }

  if(a_count>=b_count){
    cout<<"Yes"<<endl;
  }else{
    cout<<"No"<<endl;
  }
}
