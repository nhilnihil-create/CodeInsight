#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
signed main(){
  ll n,s;
  cin >> n;
  set<ll> st;
  vector<ll> v;
  if(n==3){
    cout<<"2 5 63\n";
  }else if(n==4){
    cout <<"2 5 20 63\n";
  }else if(n==5){
    cout <<"2 5 20 30 63\n";
  }else{
    st.insert(2);
    st.insert(3);
    for(int i=1;i<=30000;i++){
      if(i%6==0||i%6==2||i%6==3||i%6==4){
        v.push_back(i);
      }
    }
    for(int i=0;i<n;i++){
      st.insert(v[i]);
      s+=v[i];
    }
    ll j=n;
    if(s%6==2){
      st.erase(8);
      while(v[j]%6!=0) j++;
      st.insert(v[j]);

    }else if(s%6==3){
      st.erase(9);
      while(v[j]%6!=0) j++;
      st.insert(v[j]);

    }else if(s%6==5){
      st.erase(9);
      while(v[j]%6!=4) j++;
      st.insert(v[j]);
    }
    for(auto i:st){
      cout << i<<" ";
    }
    cout << endl;
  }
}
