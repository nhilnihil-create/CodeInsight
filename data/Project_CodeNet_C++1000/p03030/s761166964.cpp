#include<bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  using psi = pair<string,int>;
  vector<pair<psi,int>> p(N);
  for(int i=0;i<N;i++){
    string S;
    int P;
    cin >> S >> P;
    auto t = make_pair(S,-P);
    auto &tmp=p;
    tmp.at(i) = make_pair(t,i+1);
  }
  
  sort(p.begin(),p.end());//stringの方が辞書順，intの方が昇順
  
  for(int i=0;i<N;i++){
    int z;
    tie(ignore,z)=p.at(i);
    cout << z << endl;
  }
  
}  