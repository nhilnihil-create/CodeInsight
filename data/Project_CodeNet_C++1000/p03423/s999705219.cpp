#include <bits/stdc++.h>
#include <stdio.h>
#include <math.h>
#include <cmath>
using namespace std;
#define vsort(vec) sort(vec.begin(), vec.end())
#define vreverse(vec) reverse(vec.begin(), vec.end())
using ll =long long;
const ll INF =1001001001;

//最大公約数
ll gcd(ll a, ll b){
   if (a%b==0){
       return(b);
   }else{
       return(gcd(b,a%b));
   }
}
//最小公倍数
ll lcm(ll a, ll b){
   return a*b/gcd(a,b);
}

//素数判定
ll isprime(ll n){
  bool prime=true;
  for(int i=2;i<n;i++){
    if(n%i==0){
      prime=false; break;
    }
  }
if(prime){cout<<n<<" is prime"<<endl;
         }else{cout<<n<<" is not prime"<<endl;}

}
//階乗　20くらいが限界
ll factorial(ll n){
  ll a=1;ll b=n;
  for(int i=0;i<n;i++){
    a*=b;
    b--;
  }
  return a;
}

//組み合わせ　nCr
ll comb(ll a,ll b){
  ll c;
  c=factorial(a)/(factorial(a-b)*factorial(b));
  return c; 
}




/*10億7。　　　100000007
2*2行列 H*W
vector<vector<int>> vec(H,vector<int>(W));
for(int i=0;i<H;i++){
for(int j=0;j<W;j++){
cin>>vec[i][j];
  }
}

文字列→数列
string S;int A=atoi(S.c_str());
数列→文字列
int A;string S=to_string(A);
数字判定　isdigit(a)
pair宣言　pair<int,int> p(5,7);
ソート　sort(vec.begin(),vec.end());
キュー　queue<int> q;
   q.push(7);　//７が入る
   cout << q.front() << endl;  // 先頭の値を出力
   q.pop();  // 先頭の値を削除
   q.empty();
*/
//座標　corrdinateト深さヲ保持スルタメノ構造体
struct Coor{
  ll y;
  ll x;
  ll depth;
};
 ll N,M;  
 ll sy,sx,gy,gx;
 ll y,x,depth;//キューから取り出した座標
vector<string> vec;
queue<Coor> q;
vector<ll> y_vec={0,0,-1,+1};//technique
vector<ll> x_vec={-1,+1,0,0};

int BFS(){
  while(!q.empty()){
    Coor now=q.front();q.pop();//キューの先頭を取り出す
    y=now.y,x=now.x,depth=now.depth;
    
    //停止条件
    if(y==gy&&x==gx){return depth;}
    
    //上下左右４方向を探索、進むことができればキューに格納
    for(int i=0;i<4;i++){
      Coor next={y+y_vec[i],x+x_vec[i],depth+1};
      if(0<=next.y&&next.y<=N-1&&0<=next.x&&next.x<=M-1&&vec[next.y][next.x]=='.'){
        vec[next.y][next.x]='x';//同じ場所を探索しないようにする
        q.push(next);
      }
    }
  }
  return 0;
}
                   
  


int main(void){
cout<<fixed<<setprecision(14);
//cin.tie(0); ios::sync_with_stdio(false);

ll N;cin>>N;
  cout<<N/3<<endl;
 

  
  
}

