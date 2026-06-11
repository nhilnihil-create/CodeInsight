#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int solve(int a,int b,int c,int aa,int bb,int cc){
  if((aa==cc&&a%2!=c%2)||(aa!=cc&&a%2==c%2)){
    int mid=(a+c)/2;
    cout << mid << endl;
    string s;
    cin >> s;
    if(s=="Vacant")return 0;
    if(s=="Male"){
      solve(a,c,mid,aa,cc,2);
    }
    else if(s=="Female"){
      solve(a,c,mid,aa,cc,1);
    }
  }
  else{
    int mid=(c+b)/2;
    cout << mid << endl;
    string s;
    cin >> s;
    if(s=="Vacant")return 0;
    if(s=="Male"){
      solve(c,b,mid,cc,bb,2);
    }
    else if(s=="Female"){
      solve(c,b,mid,cc,bb,1);
    }
  }
}
int main(){
  int n;
  cin >> n;
  cout << 0 << endl;
  string s;
  cin >> s;
  int aa=0;
  int bb=0;
  int cc=0;
  if(s=="Vacant")return 0;
  if(s=="Male"){
    aa=2;
  }
  else aa=1;
  cout << n-1 << endl;
  string t;
  cin >> t;
  if(t=="Vacant")return 0;
  if(t=="Male"){
    bb=2;
  }
  else bb=1;
  cout << (n-1)/2 << endl;
  string o;
  cin >> o;
  if(o=="Vacant")return 0;
  if(o=="Male"){
    cc=2;
  }
  else cc=1;
  solve(0,n-1,(n-1)/2,aa,bb,cc);
}
