#include <bits/stdc++.h>
using namespace std;
 
 
int main() {
 

  // input
  string s,t;
  cin>>s>>t;

  // copy string to vector
  vector<char> s_c(s.size());
  vector<char> t_c(t.size());

  for(int i=0;i<s.size();i++){
    s_c.at(i)=s.at(i);
  }
  for(int i=0;i<t.size();i++){
    t_c.at(i)=t.at(i);
  }

  // arrange data
  sort(s_c.begin(),s_c.end());
  sort(t_c.begin(),t_c.end(),std::greater<char>());

  if(s.size()<t.size()){
    for(int i=s.size();i<t.size();i++){
      s_c.push_back('0');
    }
  }

  if(t.size()<s.size()){
    for(int i=t.size();i<s.size();i++){
      t_c.push_back('0');
    }
  }


  // check
  string s2,t2;

  for(int i=0;i<s_c.size();i++){
    s2.push_back(s_c.at(i));
    t2.push_back(t_c.at(i));
  }

#if 0
  for(int i=0;i<s_c.size();i++){
    cout<<s2.at(i);
  }
  cout<<endl;
  for(int i=0;i<t_c.size();i++){
    cout<<t2.at(i);
  }
  cout<<endl;
#endif

  // output
  if(s2<t2)
    cout<<"Yes"<<endl;
  else
    cout<<"No"<<endl;

	return 0;
}