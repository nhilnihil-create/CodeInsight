#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> P;

#define rep(i, n) for (ll i = 0; i < (int)(n); i++)
const int INF = 1001001001;
const ll mod = 1e9+7;

ll ans=0;

vector<int> A;
ll s;
string dfs (string x){
//  cout<<x<<endl;
//  cout<<A.size()<<endl;
  int keta;
  keta=x.size();
//  cout<<s<<'s'<<keta<<'k'<<endl;
  if (keta<=s){


    if(count(x.cbegin(),x.cend(),'3')>=1 & count(x.cbegin(),x.cend(),'5')>=1 & count(x.cbegin(),x.cend(),'7')>=1){
      A.push_back(stoi(x));
    }

    dfs(x+'3');
    dfs(x+'5');
    dfs(x+'7');


}
return x;
}


int main() {
  string n;
  cin>>n;
  s=n.size();
  //cout<<s<<'s'<<endl;
  if (s<3){
    cout<<0;return 0;
  }


//cout<<ans<<endl;
dfs("");

rep(i,A.size()){
  if (A[i]<=stoi(n)) ans++;
}

cout<<ans;

}
