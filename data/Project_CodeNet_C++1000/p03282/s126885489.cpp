#include <bits/stdc++.h>
using namespace std;

int main() {
  string S;
  long long K;
  cin>>S>>K;
  int i=0;
  while((S.at(i)-'0')==1 && i+1<K){
    i++;
  }
  cout<<S.at(i)<<endl;
}
