#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mod = 1000000007;

int main(){
  ll n,a,b,c;
  cin >> n >> a >> b >> c;
  vector<ll>l(8,0);
  for(int i=0; i<n; i++) cin >> l[i];
  vector<ll>ans(4);
  ll MIN = 1000000000;
  ll count=0;
  for(int p=0; p<4; p++){
    ans[p]+=l[0];
    if(p && l[0])count+=10;
    for(int q=0; q<4; q++){
      ans[q]+=l[1];
      if(q && l[1])count+=10;
      for(int r=0; r<4; r++){
        ans[r]+=l[2];
        if(r && l[2])count+=10;
        for(int s=0; s<4; s++){
          ans[s]+=l[3];
          if(s && l[3])count+=10;
          for(int t=0; t<4; t++){
            ans[t]+=l[4];
            if(t && l[4])count+=10;
            for(int u=0; u<4; u++){
              ans[u]+=l[5];
              if(u && l[5])count+=10;
              for(int v=0; v<4; v++){
                ans[v]+=l[6];
                if(v && l[6])count+=10;
                for(int w=0; w<4; w++){
                  ans[w]+=l[7];
                  if(w && l[7])count+=10;
                  
                  ll x = ans[1]-a;
                  if(x<0) x*=-1;
                  ll y = ans[2]-b;
                  if(y<0) y*=-1;
                  ll z = ans[3]-c;
                  if(z<0) z*=-1;
                  
                  if(ans[1] && ans[2] && ans[3]) MIN = min(MIN,count+x+y+z-30);
                  
                  ans[w]-=l[7];
                  if(w && l[7])count-=10;
         }
                ans[v]-=l[6];
                if(v && l[6])count-=10;
        }
              ans[u]-=l[5];
              if(u && l[5])count-=10;
       }
            ans[t]-=l[4];
            if(t && l[4])count-=10;
      }
          ans[s]-=l[3];
          if(s && l[3])count-=10;
     }
        ans[r]-=l[2];
        if(r && l[2])count-=10;
    }
      ans[q]-=l[1];
      if(q && l[1])count-=10;
   }
    ans[p]-=l[0];
    if(p && l[0])count-=10;
  }
  
  cout << MIN << endl;
  
}
  
