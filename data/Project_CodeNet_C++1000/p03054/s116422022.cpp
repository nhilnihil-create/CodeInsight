#include<bits/stdc++.h>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define rrep(i,n) for(int i = (n)-1; i >= 0; i--)
#define rep1(i,n) for(int i = 1; i <= (n); i++)
#define rrep1(i,n) for(int i = (n); i > 0; i--)

#define ll long long
#define pi pair<int, int>
#define pll pair<ll, ll>

#define MOD 1000000007
#define INF 1000000000000000LL

using namespace std;

int main(){
  int h,w,n; cin>>h>>w>>n;
  int sr, sc;cin>>sr>>sc;
  string s,t;cin>>s>>t;

  vector<string> cc = {"UD", "DU", "LR", "RL"};

  rep(i, 4){
    char ct=cc[i][0], ca=cc[i][1];
    int csr=sr, csc=sc;  
    rep(j, n){
      if(ct=='U' || ct=='D'){

        if(s[j]==ct) if(ct=='U')csr--;else csr++;
        if(csr==0 || csr==h+1) { cout<<"NO"<<endl; return 0; }
        if(t[j]==ca)if(ca=='U'){
          csr--; csr = max(csr, 1);
        }else{
          csr++; csr = min(csr, h);
        }

      }else{

        if(s[j]==ct) if(ct=='L')csc--;else csc++;
        if(csc==0 || csc==w+1) { cout<<"NO"<<endl; return 0; }
        if(t[j]==ca)if(ca=='L'){
          csc--; csc=max(csc, 1);
        }else{
          csc++; csc = min(csc, w);
        }

      }
    }
  }

  cout<<"YES"<<endl;

  return 0;
}
