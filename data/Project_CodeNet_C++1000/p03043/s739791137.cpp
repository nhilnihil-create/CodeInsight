#include<iostream>
#include<string>
#include<numeric>
#include<set>
#include<algorithm>
#include<map>
#include<vector>
using namespace std;
typedef long long li;
#define ceil(a,b) (((a)+(b)-1)/(b))
#define dist(a,b) max((a)-(b),(b)-(a))
#define yn(i) print((i)?"Yes":"No")
#define rep(i,n) for(int i=0;i<(n);i++)

#define df 0
template<class T> void print(const T& t){ cout << t << "\n"; }
template<class T, class... Ts> void print(const T& t, const Ts&... ts) { cout << t; if (sizeof...(ts)) cout << " "; print(ts...); }

// Container コンテナ型, map以外
template< template<class ...> class Ctn,class T>
std::ostream& operator<<(std::ostream& os,const Ctn<T>& v){
  auto itr=v.begin();
  while(itr!=v.end()){
    if(itr!=v.begin())cout << " ";
    cout << *(itr++);
  }
  return os;
}



int main(){
  int n,k; cin >>n >>k;
  int m=n;
  double ans=0,p=1;
  while(k){
    if(n>=k){
      ans+=(n-k+1)*p;
      n=k-1;
    }
    p/=2.0;
    if(k<=1) break;
    k=ceil(k,2);
    if(df)print(k);
  }
  printf("%.15lf\n",ans/m);
}



