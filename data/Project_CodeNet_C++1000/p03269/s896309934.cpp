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
bool prime_(int n){
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

long long gcd_(long long a, long long b){
  if(a<b){
    swap(a,b);
  }
  if(a%b==0){
    return b;
  }else{
    return gcd_(b,a%b);
  }
}
 
long long lcm_(long long x, long long y){
  return (x/gcd_(x,y))*y;
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
  
  int l;
  cin>>l;
  bool used[20][20]={};
  vector<int> cost[20][20];
  int msb;
  for(int i=19;i>=0;i--){
    if((l>>i) & 1){
      msb = i;
      break;
    }
  }
  int n=1;
  int m=0;
  for(int i=msb;i>=1;i--){
    REP(j,20){
      REP(k,20){
        if(!used[j][k])continue;
        for(int& c:cost[j][k]){
          c *= 2;
        }
      }
    }
    n++;
    used[n-2][n-1] = true;
    m += 2;
    cost[n-2][n-1].push_back(0);
    cost[n-2][n-1].push_back(1);
    if((l>>(i-1)) & 1){
      used[0][n-1] = true;
      m++;
      cost[0][n-1].push_back((l>>(i-1))-1);
    }
  }
    
  cout<<n<<' '<<m<<endl;
  REP(i,20){
    REP(j,20){
      if(used[i][j]){
        for(int c:cost[i][j]){
          cout<<i+1<<' '<<j+1<<' '<<c<<endl;
        }
      }
    }
  }
  return 0;
}
