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
  
  int n;
  cin>>n;
  
  if(n<6){
    cout<<2<<' '<<5<<' '<<63<<' ';
    if(n>3){
      cout<<20<<' ';
    }
    if(n>4){
      cout<<30<<' ';
    }
    cout<<endl;
    return 0;
  }
  
  bool used[30'010]={};
  int cnt=0;
  int mod_sum=0;
  int last_;
  REPP(i,30'000){
    if(cnt==n)break;
    if(i%6==0 || i%6==2 || i%6==3 || i%6==4){
      used[i] = true;
      last_ = i;
      cnt++;
      mod_sum += i;
      mod_sum %= 6;
    }
  }
  
  int next_;
  //nが6以上の時は良さそうな調整
  if(mod_sum==2){
    used[8] = false;
    next_ = 1+last_;
    while(next_%6){
      next_++;
    }
    used[next_]=true;
  }else if(mod_sum==3){
    used[9] = false;
    next_ = 1+last_;
    while(next_%6){
      next_++;
    }
    used[next_]=true;
  }else if(mod_sum==5){
    used[9] = false;
    next_ = 1+last_;
    while(next_%6 != 4){
      next_++;
    }
    used[next_]=true;
  }
  
  REPP(i,30'000){
    if(cnt==0)break;
    if(used[i]){
      cout<<i<<' ';
      cnt--;
    }
  }
  cout<<endl;
  
  return 0;
}
