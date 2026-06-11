#include<bits/stdc++.h>
using namespace std;
#define pcc pair<char,char>
#define mid ((head+tail)/2)
int chkdir(int p,string s,vector<pcc> arr){
  int n=s.length(),q=arr.size();
  for(int i=0;i<q;++i){
    if(s[p]==arr[i].first){
      p+=(arr[i].second=='R'?1:-1);
      if(p<0)return -1;
      if(n<=p)return 1;
    }
  }
  return 0;
}

int binsrc(int dir,string s,vector<pcc> arr){
  int n=s.length(),head=0,tail=n-1;
  while(tail-head){
    if(tail-head==1){
      bool h=false,t=false;
      h=(chkdir(head,s,arr)==dir);
      t=(chkdir(tail,s,arr)==dir);
      if(!(h||t))return (dir==1?n:-1);
      if(dir==1)return (h?head:tail);
      if(dir==-1)return (t?tail:head);
    }
    if(chkdir(mid,s,arr)==dir) (dir==1?tail:head)=mid;
    else (dir==1?head:tail)=mid+(dir==1?1:-1);
  }
  if(chkdir(head,s,arr)==dir)return head;
  else return (dir==1?n:-1);
}

int main(){
  int n,q,l,r;
  string s;
  cin>>n>>q>>s;
  vector<pcc> v(q);
  for(int i=0;i<q;++i)cin>>v[i].first>>v[i].second;
  l=binsrc(-1,s,v);
  r=binsrc(1,s,v);
  cout<<r-l-1<<endl;
  return 0;
}