#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define MOD 1000000007

int solve(int x){
  return min(abs(x),24-abs(x));
}

int main(){
  int N;
  cin>>N;
  vector<int> D(N);
  for(int i=0;i<N;i++){
    cin>>D.at(i);
  }
  vector<int> count(13,0);
  for(int i=0;i<N;i++){
    count.at(D.at(i))++;
  }
  bool flag=false;
  for(int i=1;i<12;i++){
    if(count.at(i)>2){
      flag=true;
    }
  }
  if(count.at(12)>1){
    flag=true;
  }
  if(count.at(0)>0){
    flag=true;
  }
  if(flag){
    cout<<0<<endl;
  }else{
    int ans=0;
    vector<int> a,b;
    a.push_back(0);
    for(int i=1;i<12;i++){
      if(count.at(i)==2){
        a.push_back(i);
        a.push_back(-i);
      }else if(count.at(i)==1){
        b.push_back(i);
      }
    }
    if(count.at(12)==1){
      a.push_back(12);
    }
    int n=b.size();
    for(int i=0;i<(1<<n);i++){
      int sub=12;
      vector<int> A=a;
      int res=i;
      for(int j=0;j<n;j++){
        if(res%2==0){
          A.push_back(b.at(j));
        }else{
          A.push_back(-b.at(j));
        }
        res>>=1;
      }
      int m=A.size();
      for(int j=0;j<m;j++){
        for(int k=j+1;k<m;k++){
          sub=min(sub,solve(A.at(j)-A.at(k)));
        }
      }
      ans=max(ans,sub);
    }
    cout<<ans<<endl;
  }
}
