#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0;i<(int)(n);i++)

int main(){
  string S;
  cin>>S;
  
  int l=S.size()-1;
  int num=1<<l;
  rep(tmp, num){
    bitset<10> bits(tmp);
    
    int this_sum=(S[0]-'0');
    rep(i, l){
      // cout<<this_sum<<endl;
      if(bits.test(i)){
        this_sum += (S[i+1]-'0');
      }
      else{
        this_sum -= (S[i+1]-'0');
      }
    }
    // cout<<this_sum<<endl;
    if(this_sum==7){
      cout<<S[0];
      rep(i, l){
        if(bits.test(i)){
          cout<<'+';
        }
        else{
          cout<<'-';
        }
        cout<<S[i+1];
      }
      cout<<"=7"<<endl;
      break;
    }
  }
}