#include<iostream>
#include<string>
#include<set>
using namespace std;

string s;
int K;

int main(){
  cin>>s;
  cin>>K;
  set<string> st;
  int N=s.size();
  for(int i=0;i<N;i++){
    for(int j=1;j<=N-i&&j<=K;j++){
      st.insert(s.substr(i,j));
    }
  }
  auto it=st.begin();
  for(int i=0;i<K-1;i++) it++;
  cout<<*it<<endl;
  return 0;
}
  