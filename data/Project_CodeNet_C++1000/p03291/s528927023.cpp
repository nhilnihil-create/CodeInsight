#include<iostream>
#include<vector>
using namespace std;
#define df 0
typedef long int ll;
const int MOD=1e9+7;

ll pow3(int a,int len);
ll count(string& S,string str,int cnt);



int main(){
  if(df) printf("*debug mode*\n");
  string S; cin >> S;
  int cnt=0;
  for(auto c: S){
    if(c=='?')cnt++;
  }
  ll s=0;
  (s+=count(S,"???",cnt))%=MOD;
  (s+=count(S,"??C",cnt))%=MOD;
  (s+=count(S,"?B?",cnt))%=MOD;
  (s+=count(S,"A??",cnt))%=MOD;
  (s+=count(S,"?BC",cnt))%=MOD;
  (s+=count(S,"A?C",cnt))%=MOD;
  (s+=count(S,"AB?",cnt))%=MOD;
  (s+=count(S,"ABC",cnt))%=MOD;

  cout << s;
}

ll pow3(int a,int len){
  static vector<ll> pow(len+1,0);
  if(a<=0){
    return 1;
  }
  if(pow[a]!=0) return pow[a];
  ll s;
  if(a%2){
    s=pow3(a-1,len);
    if(df)printf("3^%d->%ld\n",a-1,s);
    pow[a]=s*3%MOD;
    return pow[a];
  }
  s=pow3(a/2,len);
  pow[a]=s*s%MOD;
  if(df)printf("3^%d->%ld\n",a/2,s);
  return pow[a];
}

ll count(string& S,string str,int cnt){
  int len=S.size();
  ll s=0, a[3][len];
  if(str.at(0)==S.at(0))a[0][0]=1; else a[0][0]=0;
  a[1][0]=a[2][0]=0;
  if(df) cout << str << "\n";
  for(int i=1;i<len;i++){
    char c=S.at(i);
    for(int j=0;j<3;j++){
      if(c==str.at(j)){
	a[j][i]=a[j][i-1]+((j==0)?1:a[j-1][i-1]);
	a[j][i]%=MOD;
      }else{
	a[j][i]=a[j][i-1];
      }
      if(df) printf("%ld ",a[j][i]);
    }
    if(df) printf("\n");
  }
  for(auto a: str) if(a=='?')cnt--;
  return a[2][len-1]*pow3(cnt,len);
}

/// confirm df==0 ///