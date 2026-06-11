#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pp=pair<ll,pair<int,int>>;
using Graph=vector<vector<pair<int,ll>>>;

int main(){
  int H,W,N,sr,sc;
  string S,T;
  cin>>H>>W>>N>>sr>>sc>>S>>T;
  sr--;sc--;
  vector<bool> lr(W,false);
  int left=0,right=W-1;
  int up=0,down=H-1;
  if(S.at(N-1)=='L'){
    left++;
  }else if(S.at(N-1)=='R'){
    right--;
  }else if(S.at(N-1)=='U'){
    up++;
  }else{
    down--;
  }
  bool flag=false;
  for(int i=N-2;i>=0;i--){
    if(T.at(i)=='L'){
      right=min(right+1,W-1);
    }else if(T.at(i)=='R'){
      left=max(left-1,0);
    }else if(T.at(i)=='U'){
      down=min(down+1,H-1);
    }else{
      up=max(up-1,0);
    }
    if(S.at(i)=='L'){
      left++;
      if(left==W){
        flag=true;
        break;
      }
    }else if(S.at(i)=='R'){
      right--;
      if(right==-1){
        flag=true;
        break;
      }
    }else if(S.at(i)=='D'){
      down--;
      if(down==-1){
        flag=true;
        break;
      }
    }else{
      up++;
      if(up==H){
        flag=true;
        break;
      }
    }
  }
  if(right<left||down<up){
    flag=true;
  }
  if(sr<up||down<sr||sc<left||right<sc){
    flag=true;
  }

  if(flag){
    cout<<"NO"<<endl;
  }else{
    cout<<"YES"<<endl;
  }
}
