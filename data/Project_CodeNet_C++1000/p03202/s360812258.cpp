#include<bits/stdc++.h>
using namespace std;

using ll=long long;
int main(){
  int n;
  cin>>n;
  vector<ll> a(n);
  for(int i=0;i<n;i++) cin>>a[i];

  int lb=0;
  int ub=1e8;
  while(ub-lb>1){
    ll mid=(ub+lb)/2;
    stack<pair<pair<int,int>,int>> st;
    st.push({{0,a[0]},0});
    
    auto shrink=[&st](int sz){
      while(true){
	auto tmp=st.top(); st.pop();
	if(tmp.first.first<sz){
	  st.push({{tmp.first.first,sz},tmp.second});
	  break;
	}
      }
    };

    auto incl=[&st,mid](){
      int head=-1;
      while(true){
	if(st.size()==0){
	  return false;
	}
	auto tmp=st.top(); st.pop();

	if(tmp.second<mid-1){
	  if(tmp.first.first+1==tmp.first.second){
	    st.push({tmp.first,tmp.second+1});
	  }
	  else{
	    st.push({{tmp.first.first,tmp.first.second-1},tmp.second});
	    st.push({{tmp.first.second-1,tmp.first.second},tmp.second+1});
	  }
	  if(head!=-1) st.push({{tmp.first.second,head},0});
	  break;
	}
	if(head==-1) head=tmp.first.second;
      }
      return true;
    };
		    
    bool isok=true;
    for(int i=1;i<n;i++){
      if(a[i-1]<a[i]){
	st.push({{a[i-1],a[i]},0});
      }
      else{
	shrink(a[i]);
	if(!incl()){
	  isok=false;
	  break;
	}
      }

    }
    if(isok){
      ub=mid;
    }
    else{
      lb=mid;
    }
  }
  cout<<ub<<endl;
}