#include<bits/stdc++.h>
using namespace std;

int main()
{
  int N;scanf("%d",&N);
  set<string> s;
  string W;cin>>W;
  s.insert(W);char last=W[W.size()-1];
  for(int i=1;i<N;i++)
  {
    cin>>W;
    if(s.count(W)||last!=W[0]){printf("No");return 0;}
    s.insert(W);last=W[W.size()-1];
  }
  printf("Yes");
}