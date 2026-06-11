#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define reps(i,n) for(int i=1;i<(int)(n);i++)

typedef long long ll;
using namespace std;

int gcd(int a, int b) { //最大公約数
  if (b==0) return a;
  else return gcd(b, a%b);
}

int lcm(int a, int b) { //最小公倍数
  return a * b / gcd(a, b);
}


int main()
{
  string s[2];
  cin>>s[0]>>s[1];
  if(s[0]==s[1]){
    cout<<"No"<<endl;
    return 0;
  }
  sort(s[0].begin(),s[0].end());
  sort(s[1].begin(),s[1].end());
  reverse(s[1].begin(),s[1].end());
  string tmp=s[1];


  sort(s,s+2);

  if(s[1]==tmp){
    cout<<"Yes"<<endl;
  }else{
    cout<<"No"<<endl;
  }
  return 0;
}
