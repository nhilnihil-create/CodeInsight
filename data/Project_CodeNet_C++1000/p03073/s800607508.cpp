#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int main() {
  string S;
  cin>>S;
  int a=S.size();
  int b=0;
  int c=0;
rep(i,a){
    if(i%2==0)
    {
        if(S[i]=='0'){
            b++;
        }
    }
    else{
        if(S[i]=='1'){
            b++;
        }
    }
}
rep(i,a){
    if(i%2==1)
    {
        if(S[i]=='0'){
            c++;
        }
    }
    else{
        if(S[i]=='1'){
            c++;
        }
    }
}
  cout<<min(b,c)<<endl;
}