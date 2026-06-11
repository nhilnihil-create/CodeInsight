#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(){
  int N,Q;
  int l,r;
  string S;
  cin >> N >> Q;
  cin >> S;
  vector<int> pos;
  pos.push_back(0);
  int sum=0;
  for (int i=1;i<S.size();i++){
    if( (*(S.begin()+i-1)=='A') && (*(S.begin()+i)=='C') ){
      sum++;
    }
    pos.push_back(sum);
  }
  vector<int> ans;
  for (int i=0;i<Q;i++){
    cin >> l >> r;
    ans.push_back(pos[r-1]-pos[l-1]);
  }
//  for(auto itr=pos.begin();itr!=pos.end();itr++) cout << *itr << endl;
  for(auto itr=ans.begin();itr!=ans.end();itr++) cout << *itr << endl;
}
    
    