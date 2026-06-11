#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <algorithm>
using namespace std;
#define ll long long
const double EPS = 1e-10;

struct s_t{
  string a,b;
};

bool operator<( const s_t& left, const s_t& right ) {
  return left.a == right.a ? left.b < right.b : left.a < right.a;
}

bool operator>( const s_t& left, const s_t& right ) {
  return left.a == right.a ? left.b > right.b : left.a > right.a;
}

bool operator==( const s_t& left, const s_t& right ) {
  return (left.a == right.a) && (left.b == right.b);
}


int main(){
  int n;
  ll ans=0;
  string ss,ss1,ss2;
  cin>>n;
  cin>>ss;
  vector<s_t> s1,s2;
  s_t st;
  for(int i=0;i<n;i++){
    ss1.push_back(ss[i]);
  }
  for(int i=n;i<2*n;i++){
    ss2.push_back(ss[i]);
  }
  for(int i=0;i<(1<<n);i++){
    string p="";
    string q="";
    for(int j=0;j<n;j++){
      if(i&(1<<j)) p.push_back(ss1[j]);
      else q.push_back(ss1[j]);
    }
    reverse(q.begin(),q.end());
    st.a=p+q;
    st.b=p;
    s1.push_back(st);
  }
  for(int i=0;i<(1<<n);i++){
    string p="";
    string q="";
    for(int j=0;j<n;j++){
      if(i&(1<<j)) p.push_back(ss2[j]);
      else q.push_back(ss2[j]);
    }
    reverse(q.begin(),q.end());
    st.a=q+p;
    st.b=q;
    s2.push_back(st);
  }
  sort(s1.begin(),s1.end());
  sort(s2.begin(),s2.end());
  ll p,q;
  p=0;
  q=0;
  while(p<(int)s1.size()&&q<(int)s2.size()){
    if(s1[p]==s2[q]){
      ll a1=1;
      ll a2=1;
      ll i=1;
      while(p+i<(int)s1.size()&&s1[p+i]==s2[q]){
        i++;
        a1++;
      }
      i=1;
      while(q+i<(int)s2.size()&&s2[q+i]==s1[p]){
        i++;
        a2++;
      }
      p+=a1;
      q+=a2;
      ans+=a1*a2;
    }
    else if(s1[p]<s2[q]){
      p++;
    }
    else if(s1[p]>s2[q]){
      q++;
    }
  }
  cout<<ans<<endl;
}
