#include <bits/stdc++.h>
#define REP(i,n) for(int i=0;i<n;i++)
#define REPP(i,n) for(int i=1;i<=n;i++)
const double PI = acos(-1);
const double EPS = 1e-15;
long long INF=(long long)1E17;
#define i_7 (long long)(1E9+7)
long mod(long a){
    long long c=a%i_7;
    if(c>=0)return c;
    return c+i_7;
}
using namespace std;
bool prime(int n){
  if(n==1){
    return false;
  }else if(n==2){
    return true;
  }else{
    for(int i=2;i<=sqrt(n);i++){
      if(n%i==0){
        return false;
      }
    }
    return true;
  }
}

long long gcd(long long a, long long b){
  if(a<b){
    swap(a,b);
  }
  if(a%b==0){
    return b;
  }else{
    return gcd(b,a%b);
  }
}
 
long long lcm(long long x, long long y){
  return (x/gcd(x,y))*y;
}
 
class UnionFind {
    public:
    //各頂点の親の番号を格納する。その頂点自身が親だった場合は-(その集合のサイズ)を入れる。
    vector<int> Parent;
    
    //クラスを作るときは、Parentの値を全て-1にする。
    //以下のようにすると全てバラバラの頂点として解釈できる。
    UnionFind(int N) {
        Parent = vector<int>(N, -1);
    }
    
    //Aがどのグループに属しているか調べる
    int root(int A) {
        if (Parent[A] < 0) return A;
        return Parent[A] = root(Parent[A]);
    }
    
    //自分のいるグループの頂点数を調べる
    int size(int A) {
        return -Parent[root(A)];//先祖をrootで取っておきたい。
    }
    
    //AとBをくっ付ける
    bool connect(int A, int B) {
        //AとBを直接つなぐのではなく、root(A)にroot(B)をくっつける
        A = root(A);
        B = root(B);
        if (A == B) {
            //すでにくっついてるからくっ付けない
            return false;
        }
        
        //大きい方(A)に小さいほう(B)をくっ付けたい
        //大小が逆だったらAとBをひっくり返す。
        if (size(A) < size(B)) swap(A, B);
        
        //Aのサイズを更新する
        Parent[A] += Parent[B];
        //Bの親をAに変更する
        Parent[B] = A;
        
        return true;
    }
};

int main(){
  int n;
  long long c;
  cin>>n>>c;
  long long x[n],v[n];
  REP(i,n){
    cin>>x[i]>>v[i];
  }
  long long rget[n],lget[n];
  REP(i,n){
    if(i==0){
      rget[i]=v[i]-x[i];
    }else{
      rget[i]=rget[i-1]+v[i]-(x[i]-x[i-1]);
    }
  }
  for(int i=n-1;i>=0;i--){
    if(i==n-1){
      lget[i]=v[i]-(c-x[i]);
    }else{
      lget[i]=lget[i+1]+v[i]-(x[i+1]-x[i]);
    }
  }
  long long ans=0;
  REP(i,n){
    ans = max(ans,rget[i]);
    ans = max(ans,lget[i]);
  }
  
  long long rdget[n],ldget[n];
  REP(i,n){
    rdget[i]=rget[i]-x[i];
    ldget[i]=lget[i]-(c-x[i]);
  }
  long long l=0,r=0;
  REP(i,n){
    if(i>0){
      rdget[i]=max(rdget[i-1],rdget[i]);
    }
  }
  for(int i=n-1;i>=0;i--){
    if(i<n-1){
      ldget[i]=max(ldget[i+1],ldget[i]);
    }
  }
  REP(i,n){
    if(i>0){
      ans = max(ans,ldget[i]+rget[i-1]);
    }
    if(i<n-1){
      ans = max(ans,rdget[i]+lget[i+1]);
    }
  }
  cout<<ans<<endl;
  return 0;
}
