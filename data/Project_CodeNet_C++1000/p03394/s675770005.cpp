#include<bits/stdc++.h>
using namespace std;
using P = pair<int,int>;
int main(){
  int N;
  cin >> N;
  vector<int> two(0);
  vector<int> three(0);
  vector<int> four(0);
  vector<int> six(0);
  for(int i=1; i<=30000; i++){
    if(i %6 == 2){
      two.push_back(i);
    }
    if(i %6 == 3){
      three.push_back(i);
    }
    if(i %6 == 4){
      four.push_back(i);
    }
    if(i %6 == 0){
      six.push_back(i);
    }
  }
  
  int K = 2500;
  
  vector<P> use(0);
  for(int i=0; i<K; i++){
    P p = make_pair(two.at(i), four.at(i));
    use.push_back(p);
    p = make_pair(three.at(i), three.at(K*2-1-i));
    use.push_back(p);
  }
  for(int i=K; i<K*2; i++){
    P p = make_pair(two.at(i), four.at(i));
    use.push_back(p);
  }
  
  
  vector<int> ans(0);
  for(int i=0; i<min(N/2,K*3); i++){
    ans.push_back(use.at(i).first);
    ans.push_back(use.at(i).second);  
  }
  int n = N - ans.size(); 
  for(int i=0; i<n; i++){
    ans.push_back(six.at(i));
  }
  
  if(N == 3){
    cout << 2 << " " << 5 << " " << 63 << endl;
  }
  else{
    for(int i=0; i<N; i++){
     cout << ans.at(i) << endl;
    }
  }
  
  /*int sum = 0;
  for(int i=0; i<N; i++){
    sum += ans.at(i);
  }
  for(int i=0; i<N; i++){
    if(__gcd(ans.at(i),sum - ans.at(i)) == 1){
      cout << ans.at(i) << endl;
    }
  }*/
}