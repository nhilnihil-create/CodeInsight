#include<bits/stdc++.h>
#include <math.h>
#include <limits.h>

using namespace std;

#define rep(i,n) for(int i=0;i<(n);++i)
#define reps(i,n) for(int i=1;i<=(n);++i)
#define repr(i,n) for(int i=(n);i>=0;--i)
const long long INF = 1LL<<60;
const long long MOD = 1e9+7;
int gcd(int a,int b){if(b==0)return a;return gcd(b,a%b);}
int lcm(int a,int b){return a/gcd(a,b)*b;}
void Yes(){cout<<"Yes"<<endl;}
void No(){cout<<"No"<<endl;}
void YN(bool b){cout<<(b?"Yes":"No")<<endl;}

int n,q;
string s;
vector<char> spellC;
vector<int> spellD;

int isRemoved(int index){
  int q = spellC.size();
  rep(i,q){
    if(spellC[i]==s[index]){
      index += spellD[i];
    }
    if(index<0) return -1;
    if(index>=n) return 1;
  }
  return 0;
}

int main(void){
  long long int k,i,j;

  cin >> n >> q;
  cin >> s;
  spellC.resize(q);
  spellD.resize(q);
  rep(i,q){
    char d;
    cin >> spellC[i] >> d; 
    if(d=='L') spellD[i]=-1;
    else spellD[i]=1;
  }
  
  int left = 0;
  int right = n;
  while(right-left>1){
    int mid = (right+left)/2;
    if(isRemoved(mid)==-1)left=mid;
    else right=mid;
  }
  int mostLeft = right;
  left = 0;
  right = n;
  while(right-left>1){
    int mid = (right+left)/2; 
    if(isRemoved(mid)==1)right=mid;
    else left=mid;
  }
  int mostRight = left;

  cout << mostRight-mostLeft+1 << endl;
  
  return 0;
}


