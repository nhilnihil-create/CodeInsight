#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define Rep(i,s,n) for(int i=s;i<n;i++)
#define per(i,s,n) for(int i=n-1;i>=s;i--)
#define fi first
#define se second
#define all(c) c.begin(),c.end()
typedef long long int ll;
typedef pair<int, int> P;
typedef long double ld;
void Ans(bool x){if(x) cout<<"Yes"<<endl;else cout<<"No"<<endl;}

const ll INF=1001001001;
const ll mod=1000000007;

int main(){
  int a;
  cin>>a;
  int c=0;
  int d=0;
  if(a/100<=12&&a/100>=1){
    c++;
  }
  if(a%100<=12&&a%100>=1){
    d++;
  }
  
  if(c==1&&d==1){
    cout<<"AMBIGUOUS"<<endl;
  }
  else if(c==1) cout<<"MMYY"<<endl;
  else if(d==1) cout<<"YYMM"<<endl;
  else cout<<"NA"<<endl;
}

