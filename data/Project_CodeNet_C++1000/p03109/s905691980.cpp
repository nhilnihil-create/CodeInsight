#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n)for(ll i=0;i<n;i++)

const ll INF = 1001001001;

const double PI=3.141592653;

const ll MOD = 1000000007;//大きい素数


//提出のときに言語がc＋＋似合っていることを確認する

//絶対値の関数
int z(int a,int b){
  if(a>b) return a-b;
  else return b-a;
}



int main(){
    string s;cin>>s;
    if(s.at(5)>'0'){
      cout<<"TBD"<<endl;
    }else if(s.at(5)=='0' && s.at(6)>'4'){
      cout<<"TBD"<<endl;
    }else if(s.at(6)<='4'){
       cout<<"Heisei"<<endl;
    }
    return 0;
}
