#include<bits/stdc++.h>
using namespace std;

int main(){
  int n,m;
  cin >> n >> m;
  vector<tuple<int,int,int>>a(m,tuple<int,int,int>(0,0,0));
  for(int i=0;i<m;i++){
    cin >> get<0>(a.at(i)) >> get<1>(a.at(i));
    get<2>(a.at(i))=i;
  }
  vector<tuple<int,int,int>>b=a;
  sort(b.begin(),b.end());
  int c=1;
  for(int i=0;i<m;i++){
    if(i>0&&get<0>(b.at(i))!=get<0>(b.at(i-1))) c=1;
    get<2>(a.at(get<2>(b.at(i))))=c;
    c++;
  }
  for(int i=0;i<m;i++){
    string s,t;
    s=to_string(get<0>(a.at(i)));
    while(s.size()!=6) s='0'+s;
    t=to_string(get<2>(a.at(i)));
    while(t.size()!=6) t='0'+t;
    cout << s << t << '\n';
  }
  return 0;
}