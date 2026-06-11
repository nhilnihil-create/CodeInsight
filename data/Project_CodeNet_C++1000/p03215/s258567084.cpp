/*やったぜ。　投稿者：変態糞土方 (8月16日（水）07時14分22秒)

昨日の8月15日にいつもの浮浪者のおっさん（60歳）と先日メールくれた汚れ好きの土方のにいちゃん

（45歳）とわし（53歳）の3人で県北にある川の土手の下で盛りあったぜ。

今日は明日が休みなんでコンビニで酒とつまみを買ってから滅多に人が来ない所なんで、

そこでしこたま酒を飲んでからやりはじめたんや。

3人でちんぽ舐めあいながら地下足袋だけになり持って来たいちぢく浣腸を3本ずつ入れあった。

しばらくしたら、けつの穴がひくひくして来るし、糞が出口を求めて腹の中でぐるぐるしている。

浮浪者のおっさんにけつの穴をなめさせながら、兄ちゃんのけつの穴を舐めてたら、

先に兄ちゃんがわしの口に糞をドバーっと出して来た。

それと同時におっさんもわしも糞を出したんや。もう顔中、糞まみれや、

3人で出した糞を手で掬いながらお互いの体にぬりあったり、

糞まみれのちんぽを舐めあって小便で浣腸したりした。ああ～～たまらねえぜ。

しばらくやりまくってから又浣腸をしあうともう気が狂う程気持ちええんじゃ。

浮浪者のおっさんのけつの穴にわしのちんぽを突うずるっ込んでやると

けつの穴が糞と小便でずるずるして気持ちが良い。

にいちゃんもおっさんの口にちんぽ突っ込んで腰をつかって居る。

糞まみれのおっさんのちんぽを掻きながら、思い切り射精したんや。

それからは、もうめちゃくちゃにおっさんと兄ちゃんの糞ちんぽを舐めあい、

糞を塗りあい、二回も男汁を出した。もう一度やりたいぜ。

やはり大勢で糞まみれになると最高やで。こんな、変態親父と糞あそびしないか。

ああ～～早く糞まみれになろうぜ。

岡山の県北であえる奴なら最高や。わしは163*90*53,おっさんは165*75*60、や

糞まみれでやりたいやつ、至急、メールくれや。

土方姿のまま浣腸して、糞だらけでやろうや。*/
#include "bits/stdc++.h"
#include <unordered_set>
#define rep(i,n) for(ll i = 0; i < n; i++)
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
#define vll vector<vector<long long>>
#define vl vector<long long>
#define vi vector<int>
#define vii vector<vector<int>>
#define pb push_back
#define pf push_front
#define ld long double
#define Sort(a) sort(a.begin(),a.end())
#define cSort(a,cmp) sort(a.begin(),a.end(),cmp)
#define reSort(a) sort(a.rbegin(), a.rend())
static const ll llMAX = numeric_limits<long long>::max();
static const int intMAX = numeric_limits<int>::max();
static const ll  llMIN = numeric_limits<long long>::min();
static const int intMIN = numeric_limits<int>::min();
static const ll d_5 = 100000;
static const ll d9_7 = 1000000007;
static const ll d_9 = 1000000000;
static const double PI=3.14159265358979323846;
//<<std::setprecision(30)
template<class T>
void Printvector(std::vector<T> a){
  int size = a.size();
  rep(i,size){
    cout<<a[i]<<" ";
  }
  cout<<endl;
}
template<class T>
void Printvector(std::vector<std::vector<T>> a){
  int size = a.size();
  rep(i,size){
    int size2=a[i].size();
    rep(j,size2){
      cout<<a[i][j]<<" ";
    }
    cout<<endl;
  }
  cout<<endl;
}
template<class T>
T digitpower(T a,T b){//aのb乗を計算
  int mode=1;
  if(b==1){
    return a;
  }else if(b==0){
    return 1;
  }
  if(b%2==1){
    T tmp = digitpower(a,(b-1)/2);
    if(mode==0){
      tmp%=d9_7;
    }
    tmp*=tmp;
    if(mode==0){
      tmp%=d9_7;
    }
    tmp*=a;
    if(mode==0){
      return (tmp)%d9_7;
    }else{
      return tmp;
    }
    
  }else{
    T tmp = digitpower(a,(b)/2);
    if(mode==0){
      tmp%=d9_7;
    }
    tmp*=tmp;
    if(mode==0){
      tmp%=d9_7;
    }
    if(mode==0){
      return (tmp)%d9_7;
    }else{
      return tmp;
    }
  }
}

unordered_map<ll,ll> prime_factor(int64_t n) {
  unordered_map<ll,ll> ret;
  for(int64_t i = 2; i * i <= n; i++) {
    while(n % i == 0) {
      ret[i]++;
      n /= i;
    }
  }
  if(n != 1) ret[n] = 1;
  return ret;
}
struct datas{
  int num;
  int index;
};
bool cmp(const datas &a, const datas &b)
{
    return a.num < b.num;
}
template<class T>
vector<T> getaccum(vector<T> a){
  int size=a.size();
  vector<T> ans(size);
  ans[0]=a[0];
  for(int i=0;i<size-1;i++){
    ans[i+1]=ans[i]+a[i+1];
    //ans[i+1]%=d9_7;
  }
  return ans;
}
  multiset<int> c;
  //木構造グラフ
struct edge{
  int to;
  ll length;
  int num;
  int pair;
};
struct treev{
  int num;
  vector<int> nexts;
};
vector<treev> vs;
vector<edge> es;
 
int cmax=0;
void createtreenode(int num){//引数は頂点の数
  vs=vector<treev>(num);
  /*treev* newt;
  try{
      treev* newt=new treev;
  }
  catch (std::bad_alloc&) {
      // メモリ確保に失敗
      // エラー処理
  }*/
  rep(i,num){
    vs[i].num=i;
  }
  return ;
}
void insertree_bidire(ll len,int Va,int Vb,int num){//結ぶ頂点を
  //双方向
  es.pb({Va,len,num,-1});
  es.pb({Vb,len,num,-1});
  int size=es.size();
  es[size-1].pair=size-2;
  es[size-2].pair=size-1;
  vs[Va].nexts.push_back(size-1);
  vs[Vb].nexts.push_back(size-2);
  
  return;
}
void insertree_unidire(ll len,int Va,int Vb,int num){//結ぶ頂点を
  //単方向,aからbへ
  es.pb({Vb,len,num,-1});
  int size=es.size();
  es[size-1].pair=-1;
  vs[Va].nexts.push_back(size-1);
  return;
}
void DFS(int root,ll depth,int pre){
  //ここにやりたい処理を書く
  int ncnt=0;
  for(auto i:vs[root].nexts){
    if(pre==es[i].to){
      continue;
    }
    
    DFS(es[i].to,depth+es[i].length,root);
  }
  return;
}
struct operatedata{
  int num;
  int prenum;
  ll depth;
};
deque<operatedata> opera;
vi past;
int tmpdepthmax=0;
int ngflag;
vi nums;
void BFS(int ini){
  opera.clear();
  opera.pb({ini,-1,0});
  int pre=-1;
  while(opera.size()!=0 &&ngflag==0){
    int root=opera.front().num;
    int pre=opera.front().prenum;
    ll depth=opera.front().depth;
    opera.pop_front();
    //ここにやりたい処理を書く
    nums[root]=*(--c.end());
    c.erase(--c.end());
    for(int i:vs[root].nexts){
      if(es[i].to==pre){
        continue;
      }
      opera.push_back({es[i].to,root,depth+es[i].length});
    }
  }
  return;
}


int main(void){
  int n,k;
  cin>>n>>k;
  vl a(n);
  rep(i,n)cin>>a[i];
  vl accum=getaccum(a);
  //Printvector(accum);
  multiset<ll> nums;
  for(int i=0;i<n;i++){
    for(int j=i;j<n;j++){
      if(i==0){
        nums.insert(accum[j]);
      }else{
        nums.insert(accum[j]-accum[i-1]);
      }
    }
  }
  //cout<<nums.size()<<endl;
  ull ans=0;
  int cnt=0;
  rep(i,44){
    ull now=digitpower((ull)2,(ull)(43-i));
    int flag=0;
    cnt=0;
    for(auto i:nums){
      if(((ans|now)&i) == (now|ans))cnt++;
      if(cnt>=k){
        flag=1;
        break;
      }
    }
    if(flag==1){
      ans|=now;
    }
  }
  
  cout<<ans<<endl;
  return 0;
}
