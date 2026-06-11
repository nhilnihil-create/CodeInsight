#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(i, n) for (int i = 1; i < (int)(n+1); i++)
int f(int i){
    if(i%2==0){
        return i/2;
    }else{
        return i*3+1;
    }
}
int main() {
    string S;
    cin>>S;
    int a=S.size();
    int ans=0;
    int b=0;
    rep(i,a){
        if(S[i]=='A'||S[i]=='T'||S[i]=='C'||S[i]=='G'){
            b++;
        }
        else{
            if(ans<b){
                ans=b;
            }
            b=0;
        }
    }
  if(ans<b){
    ans=b;
  }
  cout<<ans<<endl;
}
