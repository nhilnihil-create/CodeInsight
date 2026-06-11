#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define MAX 300003
#define MOD 1000000007
#define INF 1000000000000000000
using Graph=vector<vector<int>>;

int main(){
  ll K,A,B;
  cin>>K>>A>>B;
  ll count=K-(A-1);
  if(K<A+1||B-A<=2){
    cout<<K+1<<endl;
  }else if(count%2==0){
    cout<<A+(B-A)*count/2<<endl;
  }else{
    cout<<A+(B-A)*(count/2)+1<<endl;
  }
}
