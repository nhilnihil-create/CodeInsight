#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
#define all(v) v.begin(),v.end()
using namespace std;
typedef long long ll;
 
int main(){
  int a,b,c,d,e;
  cin>>a>>b>>c>>d>>e;
  vector<int> time={a,b,c,d,e};
  vector<int> index={0,1,2,3,4};
  int Besttime=(int) 1e+9;
  do{
    int nowtime=0;
    rep(i,5){
      while(nowtime%10!=0) nowtime++;
      nowtime+=time[index[i]];
    }
    Besttime=min(nowtime,Besttime);
  }while(next_permutation(all(index)));
  cout<<Besttime<<endl;
}