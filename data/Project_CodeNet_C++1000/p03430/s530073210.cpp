#include<bits/stdc++.h>
using namespace std;
using Int = signed;

template<typename T>
vector<T> make_v(size_t a){return vector<T>(a);}
template<typename T>
vector<vector<T> > make_v(size_t a,size_t b){
  return vector<vector<T> >(a,make_v<T>(b));
}
template<typename T>
vector<vector<vector<T> > > make_v(size_t a,size_t b,size_t c){
  return vector<vector<vector<T> > > (a,make_v<T>(b,c));
}

template<typename T,typename V>
typename enable_if<is_class<T>::value==0>::type
fill_v(T &t,const V &v){t=v;}

template<typename T,typename V>
typename enable_if<is_class<T>::value!=0>::type
fill_v(T &t,const V &v){
  for(auto &e:t) fill_v(e,v);
}


template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}

//INSERT ABOVE HERE
signed main(){
  string s;
  Int k;
  cin>>s>>k;
  Int n=s.size();

  const Int INF = 1e5;
  auto dp=make_v<Int>(k+2,n,n);
  fill_v(dp,-INF);

  for(Int i=0;i<n;i++){
    dp[0][i][i]=1;
    for(Int j=i+1;j<n;j++)
      dp[s[i]!=s[j]][i][j]=2;
  }

  for(Int l=1;l<=n;l++){
    for(Int i=0;i<=k;i++){
      for(Int p=0;p+l<=n;p++){
	Int q=p+l-1;
	//cout<<i<<" "<<p<<" "<<q<<":"<<dp[i][p][q]<<endl;
	if(p  >0) chmax(dp[i][p-1][q],dp[i][p][q]);
	if(q+1<n) chmax(dp[i][p][q+1],dp[i][p][q]);
	if(p>0&&q+1<n) chmax(dp[i+(s[p-1]!=s[q+1])][p-1][q+1],dp[i][p][q]+2);
      }
    }
  }
  
  Int ans=0;
  for(Int i=0;i<=k;i++) chmax(ans,dp[i][0][n-1]);
  cout<<ans<<endl;
  return 0;
}
