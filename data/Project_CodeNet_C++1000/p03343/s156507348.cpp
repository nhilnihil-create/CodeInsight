#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
int main(){
  int n,k,q;cin>>n>>k>>q;
  int a[n];
  vector<pii> vv;
  for(int i=0;i<n;i++){
    cin>>a[i];
    vv.push_back(make_pair(a[i],i));
  }
  sort(vv.begin(),vv.end());
  int ans=1000000000;
  set<int> st;
  st.insert(-1);
  st.insert(n);
  for(int i=0;i<n;i++){
    int ps=vv[i].second;
    vector<int> v;
    for(auto itr=st.begin();;){
      vector<int> w;
      int now1=*itr;
      itr++;
      int now2=*itr;
      now2--;
      if(now2-now1>=k){
        for(int j=now1+1;j<=now2;j++){
          w.push_back(a[j]);
        }
        sort(w.begin(),w.end());
        for(int j=0;j<now2-now1-k+1;j++){
          v.push_back(w[j]);
        }
      }
      if(itr==st.end())break;
    }
    if(v.size()<q)break;
    sort(v.begin(),v.end());
    ans=min(ans,v[q-1]-v[0]);
    st.insert(ps);
  }
  cout<<ans<<endl;
}