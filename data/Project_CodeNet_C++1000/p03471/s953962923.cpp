#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(i, n) for (int i = 1; i < (int)(n+1); i++)
int main() {
 int N,Y;
 cin>>N>>Y;
 bool ans=false;
rep(i,N+1){
    rep(j,N+1){
         int k=N-i-j;
      		if(0<=k){
            if(i*10000+j*5000+k*1000==Y){
                cout<<i<<" "<<j<<" "<<k<<endl;
                ans=true;
              	i+=N;
              	j+=N;
              k+=N;
              break;
            }
            }
        }
    }

 if(ans==false){
     cout<<-1<<" "<<-1<<" "<<-1<<endl;
 }
}
