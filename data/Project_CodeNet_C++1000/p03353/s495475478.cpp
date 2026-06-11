#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0;i<n;i++)
#define erep(i,n) for(int i = 0;i<=n;i++)
#define rep1(i,n) for(int i = 1;i<n;i++)
#define erep1(i,n) for(int i = 1;i<=n;i++)
typedef long long ll;
#define vint vector<int>
#define vstring vector<string>
#define vll vector<ll>
#define vbool vector<bool>
#define INF 100000000

ll gcm(ll a,ll b);

int main(){
  string s;
  int N;
  cin >> s >> N;
  int k = s.length();
  vstring A(k);
  rep(i,k){
    A[i] = s.substr(i,(k-i));
  }
  sort(A.begin(),A.end());
  //rep(i,k) cout << A[i] << endl;
  vstring ans(10000000);
  int judge = 0;
  int last = 0;
  bool ansans = false;
  rep(i,k){
    rep(j,A[i].length()){
      bool ok = false;
      if(i == 0){
        ans[judge] = A[i].substr(0,(j+1));
        judge++;
        last++;
      }
      else{
        if(last < (j+1)){
          ans[judge] = A[i].substr(0,(j+1));
          judge++;
          last = j + 1;
        }
        else if(A[i-1][j] != A[i][j]){
          //cout << "i" << i << "j" << j << endl;
          ok = true;
          for(int t = j;t<A[i].length();t++){
            //cout << "t" << t << endl;
            //cout << judge << endl;
            ans[judge] = A[i].substr(0,(t+1));
            judge++;
          }
          if(ok){
            last = A[i].length();
            break;
          }
        }
      }
      if(judge > 5){
        ansans = true;
        break;
      }
      //cout <<"last" <<  last << endl;
      //cout <<"judge"<< judge << endl;
    }
    if(ansans) break;
  }
  cout << ans[N-1] << endl;
}




