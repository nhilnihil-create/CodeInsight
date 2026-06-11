#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define reps(i,n) for(int i=1;i<(int)(n);i++)

typedef long long ll;
using namespace std;

ll gcd(ll a, ll b) { //最大公約数
  if (b==0) return a;
  else return gcd(b, a%b);
}

ll lcm(ll a, ll b) { //最小公倍数
  return a * b / gcd(a, b);
}

ll digit_sum(ll a){ //10進桁和
  ll ans=0;
  while(a>0){
    ans+=a%10;
    a/=10;
  }
  return ans;
}



int main()
{
  ll h,w;
  char s[100][100];
  cin>>h>>w;
  reps(i,h+1){
    reps(j,w+1)cin>>s[i][j];
  }

  reps(i,h+1){
    reps(j,w+1){
      if(s[i][j]=='#'&&s[i-1][j]!='#'&&s[i][j-1]!='#'&&s[i+1][j]!='#'&&s[i][j+1]!='#'){
        cout<<"No"<<endl;
        return 0;
      }
    }
  }
  cout<<"Yes"<<endl;
  return 0;
}
