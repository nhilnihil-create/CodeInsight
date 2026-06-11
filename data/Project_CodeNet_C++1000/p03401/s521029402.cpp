#include <bits/stdc++.h>
#include <map> // pair
using namespace std;

typedef long long ll;
#define vec vector<int>
#define vecll vector<ll>
#define vpair vector<pair<int, int>>
#define vpairll vector<pair<ll, ll>>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define rep(i,n)   for(int i=(int)0; i<(int)n; i++)
#define llrep(i,n)   for(ll i=(ll)0; i<(ll)n; i++)
#define REP(i,m,n) for(int i=(int)m; i<(int)n; i++)
#define all(var)     (var).begin(), (var).end()
#define prt(var)     cout << var << endl
#define prt_dbl(i,var) cout<<fixed<<setprecision(i)<<var<<endl;
template <typename Val,typename Number>
//use ll or int for gcd
Val gcd(Val a, Val b) {
    if (b==0) return a;
    else return gcd(b, a%b);
}
//count vector and return pair (count,vector item)
template <typename Val,typename Number>
void count_vector(vector<Val>* A,vector<pair<Number,Val>>*R){
  sort(A->begin(),A->end());
  int count = 1;
  rep(i,A->size()){
    if(i<A->size()-1){
      if(A->at(i)==A->at(i+1))count++;
      else{
        R->push_back(make_pair(count,A->at(i)));
        count = 1;
      }
    }else{
      R->push_back(make_pair(count,A->at(i)));
      count = 1;
    }
  }
}

//---------------------------------------------------------------

int main(){
  int N;
  cin>>N;
  vector<int> A(N);
  vector<int> detA(N);
  ll total = 0;
  rep(i,N){
    cin>>A.at(i);
    if(i==0){
      detA.at(i)=abs(A.at(i));
    }else{
      detA.at(i)=abs(A.at(i)-A.at(i-1));
    }
    total+=detA.at(i);
  }
  A.push_back(0);
  detA.push_back(abs(A.at(N-1)));
  total+=detA.at(N);

  rep(i,N){
    ll ans;
    if(i==0){
      ans = total-detA.at(0)-detA.at(1)+abs(A.at(i+1));
    }else{
      ans = total-detA.at(i)-detA.at(i+1)+abs(A.at(i+1)-A.at(i-1));
    }
    cout<<ans<<endl;
  }


}
