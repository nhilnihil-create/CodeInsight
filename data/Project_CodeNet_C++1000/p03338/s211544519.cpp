
#include <bits/stdc++.h>
#include <string.h>
#include <vector>
//s#define rep(i, n) for (int i = 0; i < (n); i++)
#define MAX 10000

using namespace std;

#define ll long long
#define pb push_back
//#define mp make_pair
#define all(a) (a).begin(),(a).end()
#define rep(i,a,n) for(int i=a; i<n; i++)
#define r0 return 0
#define INF (int)1e15
#define MOD 1000000007
//#define N 12
#define sz 1000*1000


 int main(){

 int n ; cin>>n;
 string s; cin>>s;

  int ans=0;

  for(int i=0;i<n;i++){

    int ani[26] = {0},lin[26] = {0};
      for(int j=0;j<i;j++){
            ani[s[j]-'a'] = 1;
      }

      for(int k=i;k<n;k++){
            lin[s[k]-'a'] = 1;
      }

   int cnt=0;
      for(int i=0;i<26;i++){
            if(ani[i] == 1 && lin[i] == 1)
                  cnt++;
      }

      ans = max(ans,cnt);

  }

  cout<<ans<<endl;

 return 0;
 }
