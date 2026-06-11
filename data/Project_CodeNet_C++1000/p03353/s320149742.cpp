#include <bits/stdc++.h>
#include <math.h>
#define ALL(a)    a.begin(), a.end() 
#define rep(i, K, N)  for(long long int i = K; i < N; i++)
#define ll long long int
#define PP 1000000007
using namespace std;

int main(){
string S;cin >> S;
ll K, L, cnt1 = 0;cin >> K;
map<char, ll> M;
map<string, ll> Ans;

L = S.size();

rep(i, 0, L)M[S[i]]++;

for(auto x : M ){

  cnt1++;

  if(cnt1 > 5)break;

  char c = x.first;

  rep(i, 0, L){

    if(S[i] == c){

      ll j = i;

      while(j < min(i + 5, L)){

        Ans[S.substr(i, j - i + 1)]++;
        
        j++;

      }

    }

  }

}
  
cnt1 = 0;

for(auto x : Ans ){
  
  cnt1++;
  
  if(cnt1 == K)cout << x.first << endl;

}

}