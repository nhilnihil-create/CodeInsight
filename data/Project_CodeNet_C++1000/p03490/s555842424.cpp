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
  string s;
  cin>>s;
  int x,y;
  cin>>x>>y;
  vector<int> dx,dy;
  int cntx=0,cnty=0;
  int slen=s.size();
  int cnt=0;//連続する'F'の数を数える
  bool flag=true;//x方向の移動か否か
  REP(i,slen){
    if(s[i]=='T'){
      if(flag){
        dx.push_back(cnt);
        cntx++;
      }else{
        dy.push_back(cnt);
        cnty++;
      }
      cnt=0;
      flag = !flag;
    }else{
      cnt++;
      if(i==slen-1){
        if(flag){
          dx.push_back(cnt);
          cntx++;
        }else{
          dy.push_back(cnt);
          cnty++;
        }
      }
    }
  }
  if(cnty==0){
    if(x==slen && y==0){
      cout<<"Yes"<<endl;
    }else{
      cout<<"No"<<endl;
    }
    return 0;
  }
  vector<vector<bool>> dpx(cntx,vector<bool>(16001,false));
  vector<vector<bool>> dpy(cnty,vector<bool>(16001,false));
  REP(i,cntx){
    if(i==0){
      dpx[i][dx[i]+8000]=true;
    }else{
      REP(j,16001){
        if(0<=j-dx[i] && j+dx[i]<16001){
          dpx[i][j]=dpx[i-1][j-dx[i]] | dpx[i-1][j+dx[i]];
        }else if(0<=j-dx[i]){
          dpx[i][j]=dpx[i-1][j-dx[i]];
        }else if(j+dx[i]<16001){
          dpx[i][j]=dpx[i-1][j+dx[i]];
        }else{
          continue;
        }
      }
    }
  }
  REP(i,cnty){
    if(i==0){
      dpy[i][dy[i]+8000]=true;
      dpy[i][-dy[i]+8000]=true;
    }else{
      REP(j,16001){
        if(0<=j-dy[i] && j+dy[i]<16001){
          dpy[i][j]=dpy[i-1][j-dy[i]] | dpy[i-1][j+dy[i]];
        }else if(0<=j-dy[i]){
          dpy[i][j]=dpy[i-1][j-dy[i]];
        }else if(j+dy[i]<16001){
          dpy[i][j]=dpy[i-1][j+dy[i]];
        }else{
          continue;
        }
      }
    }
  }
  
  if(0<=x+8000 && x+8000<16001 && 0<=y+8000 && y+8000<16001 && dpx[cntx-1][x+8000] && dpy[cnty-1][y+8000]){
    cout<<"Yes"<<endl;
  }else{
    cout<<"No"<<endl;
  }
  return 0;
}