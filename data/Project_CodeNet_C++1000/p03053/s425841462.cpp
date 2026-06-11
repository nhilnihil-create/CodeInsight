#include <bits/stdc++.h>
/* S.size() s.substr(l,r=s.size()-l) -> l文字目からr文字分
__gcd()　lower_bound(a+l,a+r,x)-a でindex
// 配列  -> min/max({}) 
// vector-> *min_element(a+l,a+r)  *忘れず lとrで[l,r) 
//reverse(a+l,a+r)   配列aの[l,r)を逆順に strはreverse(all(s))
//sort(a+l,a+r,greater <int>()) 配列aの[l,r)昇順sort,大きい順はgreater<type>()
//vectorならall(v)
clock()/CLOCKS_PER_SEC で秒数
vector v.push_back(x),v.pop_back()
q.push(x),front()で先頭を返す,pop()で削除, size(),empty()
<deque>(push/pop)_(front/back)/fornt/back/insert/
priority_queue 宣言は priority_queue< Type, vector<Type>, greater<Type>> Q1; 
// pq.push(x),top()で参照 pop()で削除   greaterで最小 lessで最大がtopに*/
using namespace std;
#define all(v) (v).begin(), (v).end()
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define print(i) std::cout << (i) << '\n'
#define rrep(i,n) for(int (i)=(n)-1;(i)!=-1;(i)--)
#define vep(i,v) for(auto (i)=v.begin();(i)<(v.end());(i)++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
inline long long ceildiv(long long a, long long  b) { return (a+b-1)/b; }
typedef pair<long long,long long> P;
typedef pair<int,int> PI;
using Graph = std::vector<std::vector<int> >;
const long long inf = 10e17;
const long long mod = 1000000007;
//int |x|<=2*10**9     long |x|<= 9*10**18
//printf(".(小数点以下の桁数)lf(double時、float ならf)")
#define ll long long
int maze[1100][1100];
int x[4]={0,0,1,-1};
int y[4]={1,-1,0,0};
int main(){
int h,w;cin>>h>>w;
vector<PI> now,nex;
rep(i,h){
  string ss;cin>>ss;
  rep(j,w){
    if (ss[j]=='#'){
      now.push_back(PI(i,j));
      maze[i][j]=1;}
  }
}
int ans=0;
bool flag=true;
while (flag){
flag=false;

while(!now.empty()){
  PI p=now[now.size()-1];
  now.pop_back();
rep(k,4){
  
  int a=p.first+x[k],s=p.second+y[k];
  if (0<=a&&a<h && 0<=s&&s<w&& maze[a][s]!=1){
  maze[a][s]=1;flag=true;
  nex.push_back(PI(a,s));}
}}
now.clear();
ans++;swap(now,nex);
}
print(ans-1);
}