#include <bits/stdc++.h>

#define FOR(i, a, b) for(int i = a;i < b;i++)
#define For(i, a) FOR(i, 0, a)
#define REV(i, a, b) for(int i = b-1;i >= a;i--)
#define Rev(i, a) REV(i, 0, a)
#define REP(a) For(i, a)
#define DEBUG_PRINT(...) fprintf(stderr, __VA_ARGS__)

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair<int, int> pi;
typedef vector<int> vi;
void print_pair(pi a){
  cerr<<"("<<a.first<<", "<<a.second<<") ";
}
template<int T1, int T2>
void print_2d(int a[T1][T2], int x, int y){
  For(i, x){
    For(j, y){
      cerr<<a[i][j]<<" ";
    }
    cerr<<endl;
  }
}
template<class T>
void print_array(T a[],size_t n){
  cerr<<"array:";
  REP(n-1)cerr<<a[i]<<",";
  cerr<<a[n-1]<<endl;
}

ll H,W,N;
pair<ll,ll> V[200001];
ll kanou[200001];

int main(){
  fill(V,V+200001,make_pair(-1,-1));
  cin>>H>>W>>N;
  int index=0;
  REP(N){
    ll tmp1,tmp2;
    cin>>tmp1>>tmp2;
    if(tmp1<tmp2)
      continue;
    else{
      V[index]=make_pair(tmp1-1,tmp2-1);
      index++;
    }
  }
  sort(V,V+index);
  fill(kanou,kanou+W+1,H);
  kanou[0]=0;
  ll j=0;
  for (ll i = 1; i < H; i++) {
    auto itr=lower_bound(V,V+index,make_pair(i,j+1));
    while(*itr==make_pair(i,j+1)&&i<H){
        i++;
        itr=lower_bound(V,V+index,make_pair(i,j+1));
    }
    kanou[j+1]=i;
    j++;
  }
  ll ans=0;
  REP(index){
    if(kanou[V[i].second]<V[i].first){
      ans=V[i].first;
      goto end2;
    }
  }
  cout<<H<<endl;
  return 0;
end2:
  cout<<ans<<endl;
  return 0;
}

