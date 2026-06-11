#include <bits/stdc++.h>
using namespace std ;
#define ll long long 

pair<ll ,ll> dp[3001][3001];
int main(){

string s , t ; cin >> s >> t ;
ll sl , tl ; sl = s.size(); tl = t.size();
dp[0][0].first = 0;dp[0][0].second = 0;
 dp[1][0].first= 0;dp[1][0].second= 0;
  dp[0][1].first= 0; dp[0][1].second= 0; ll ans = 0; pair<ll,ll> ind ;
for(ll i=0; i<=sl ; i++){
    for(ll j=0 ; j<=tl; j++){
    if(i==0 || j==0){ dp[i][j].first= 0; dp[i][j].second =0;}
    else {
 ll maxi = 0;  maxi = max(dp[i-1][j].first , dp[i][j-1].first);
   ll flag =0;
  if( s[i-1]== t[j-1]){ flag = 1;
      maxi= max(maxi , dp[i-1][j-1].first+ 1); }
     dp[i][j].first = maxi; ll sec ;
     if(maxi== dp[i-1][j-1].first+ 1 && flag){ sec =1  ;}
     else if(maxi==dp[i-1][j].first){sec = 2;}
     else { sec = 3;}  
       ans = max(ans, maxi); if(ans==maxi){ ind = make_pair(i,j); }
        dp[i][j].second = sec;
    }
}}

 string ret = ""; ll count =0;
  // backtracking to get the answer  
    while(count< ans){
           if(dp[ind.first][ind.second].second==1){ ret= ret+ s[ind.first-1]; ind.first--; ind.second--; count++;}
           else if(dp[ind.first][ind.second].second==2){ind.first--;}
           else { ind.second--;}
    }
   ll d = ret.size();

   for(ll i= d-1; i>=0; i--){ cout << ret[i];} cout << endl;

}