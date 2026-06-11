#include<bits/stdc++.h>
using ll=long long;
using namespace std;
int main(){
  //入力準備
  string s;
  cin>>s;
  vector<int>a(4);
  int sumplus=0;
  int summinus=0;
  int bitans;
  
  for(int i=0;i<4;i++){a[i]=s[i]-'0';}
  for(int bit=0;bit<(1<<4);bit++){
    //ビット演算お決まり
    bitset<4>tm(bit);
    bitset<4>xo("1111");
    xo=xo^tm;
    sumplus=0;
    summinus=0;
    for(int i=0;i<4;i++){
      if(tm.test(i)){
	sumplus+=a[i];
      }
      if(xo.test(i)){
	summinus+=a[i];
      }//実際にはelse文でsumplusから引くという操作をするだけで十分であるが、ビット操作に慣れるためやや回りくどいことをした。
    }
    if(sumplus-summinus==7){bitans=bit;break;}
  }

  //出力準備
  bitset<4>bitman(bitans);
    string ans="";
    for(int i=0;i<4;i++){
      if(i!=0&&bitman.test(i))ans+="+";
      else if(i==0)ans+="";
      else ans+="-";
      ans+=s[i];
    }
    ans+="=7";
    cout<<ans<<endl;
    
    
  return 0;
}
