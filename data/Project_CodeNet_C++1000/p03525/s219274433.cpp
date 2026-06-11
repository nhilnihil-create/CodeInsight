#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin>>N;
  int D[N];
  int A[25];
  for(int i=0;i<24;i++){
    A[i]=0;
  }
  A[0]=1; 
  A[24]=1;
  int flag=1;
  map<int,int>mp;
  for(int i=0;i<N;i++){
    cin>>D[i];
    if(D[i]==0){
      cout<<0<<endl;
      return 0;
    }
  }
  sort(D,D+N);
  for(int i=0;i<N;i++){
    if(flag==1){
      A[D[i]]=1;
      mp[D[i]]++;
    }
    else{
      A[24-D[i]]=1;
      mp[24-D[i]]++;
    }
    flag*=(-1);
  }
  int maxans=12;
  vector<int>T;
  
  for(int i=0;i<24;i++){
    if(A[i]==1){
      T.emplace_back(i);
      //cout<<i<<"#"<<endl;
    }
  }
  T.push_back(24);
  for(int i=0;i<T.size();i++){
     maxans=min(maxans,abs(T[i+1]-T[i]));
  }
  
  for(auto itr=mp.begin();itr !=mp.end();itr++){
    if((itr->second)>1){
      cout<<0<<endl;
      return 0;
    }
  }

  
  cout<<maxans<<endl; 

  return 0;
}

    
    