#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
struct __INIT{__INIT(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(15);}} __init;
#define max3(a,b,c) max(a,max(b,c))
#define min3(a,b,c) min(a,min(b,c))
constexpr int MOD=1000000007;
//constexpr int MOD=998244353;
#define INF (1<<30)
#define LINF (lint)(1LL<<56)
#define endl "\n"
#define rep(i,n) for(lint (i)=0;(i)<(n);(i)++)
#define reprev(i,n) for(lint (i)=(n-1);(i)>=0;(i)--)
#define Flag(x) (1<<(x))
#define Flagcount(x) __builtin_popcount(x)
#define pint pair<int,int>
#define pdouble pair<double,double>
#define plint pair<lint,lint>
#define fi first
#define se second
typedef long long lint;
int dx[8]={1,1,0,-1,-1,-1,0,1};
int dy[8]={0,1,1,1,0,-1,-1,-1};
const int MAX_N=2e5+5;

lint LCM(lint a,lint b){
  if(a==0 || b==0) return 0;
  lint tmp,r,x;
  x=a*b;
  if(a<b) tmp=a,a=b,b=tmp;
  r=a%b;
  while(r!=0) a=b,b=r,r=a%b;
  x=x/b;
  return x;
}

lint GCD(lint a,lint b){
  if(a==0 || b==0) return max(a,b);
  else return (a*b)/LCM(a,b);
}

int main(void){
    string S;
    cin >> S;
    int N=S.length();
    set<char> alf;
    rep(i,26) alf.insert('a'+i);
    rep(i,N) alf.erase(S[i]);
    if(N<26){
        cout << S << *alf.begin() << endl;
        return 0;
    }
    char s[26];
    rep(i,N) s[i]=S[i];
    if(!next_permutation(S.begin(),S.end())){
        cout << -1 << endl;
        return 0;
    }
    rep(i,26){
        if(S[i]!=s[i]){
            cout << S[i] << endl;
            break;
        }
        else cout << S[i];
    }
}
