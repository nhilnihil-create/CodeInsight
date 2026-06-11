#include<bits/stdc++.h>
using namespace std;

int main(){
  int N,M;
  cin >> N;
  string s[N];
  for(int i=0;i<N;i++){
    cin >> s[i];
  }
  cin >> M;
  string t[M];
  for(int i=0;i<M;i++){
    cin >> t[i];
  }
  int max,count;
  for(int i=0;i<N;i++){
    for(int k=0;k<N;k++){
      if(s[i]==s[k]) count++;
    }
    for(int j=0;j<M;j++){
      if(s[i]==t[j]) count--;
    }
    if(count>max) max=count;
    count =0;
  }
  if(max<0) max=0;
  cout << max << endl;
}