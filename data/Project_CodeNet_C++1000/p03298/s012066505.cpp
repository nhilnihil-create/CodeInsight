#include<iostream>
#include<string>
#include<map>
#include<utility>
#include<algorithm> // reverse
using namespace std;
#define df 0

void in(string const& S,int a,map<pair<string,string>,int>& m);
int search(string const& S,int a,map<pair<string,string>,int>& m);


int main(){
  int n; cin >> n;
  string S; cin >> S;
  if(df)cout << S;
  string T=S.substr(n,n);
  reverse(T.begin(),T.end());
  S=S.substr(0,n);
  
  if(df)cout << "\n" << S << "\n" << T << "\n" ;
  map<pair<string,string>,int> m;
  for(int i=0,limit=1<<n; i<limit; i++){
    in(S,i,m);
  }
  /*
  if(df){
    for (const auto& [key, value] : m){
      std::cout << key.first << " " << key.second << " => " << value << "\n";
    }
  }
  */
  long int cnt=0;
  for(int i=0,limit=1<<n; i<limit; i++){
    cnt+=search(T,i,m);
  }
  cout << cnt <<endl;
}

void in(string const& S,int a,map<pair<string,string>,int>& m){
  string str1,str2;

  if(df)printf("a=%d: ",a);
  int len=S.size();
  for(int i=0;i<len;i++){
    if(a%2){
      str1.push_back(S.at(i));
    }else{
      str2.push_back(S.at(i));
    }
    a/=2;
  }
  if(df)cout << str1 << " " << str2 << endl;
  pair<string,string> P=make_pair(str1,str2);
  auto itr=m.find(P);
  if(itr==m.end()){
    m[make_pair(str1,str2)]=1;
  }else{
    m[make_pair(str1,str2)]++;
  }
}

int search(string const& S,int a,map<pair<string,string>,int>& m){
  string str1,str2;
  int len=S.size();
  for(int i=0;i<len;i++){
    if(a%2){
      str1.push_back(S.at(i));
    }else{
      str2.push_back(S.at(i));
    }
    a/=2;
  }
  return m[make_pair(str1,str2)];
}

/// confirm df==0 ///
