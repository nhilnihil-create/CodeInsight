#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define strall(v) (v).cbegin(),(v).cend()
using namespace std;
using ll = long long;
using P = pair<int,int>;
using Graph = vector<vector<int>>;
template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

vector<bool> a(105,false);

int main(){
 int a,b,cnt=0;
 cin >> a >> b;
 for(int i=1;i<=a;i++) for(int j=1;j<=12;j++){ 
   if(i == a) if(j > b) break;
   if(i == j) cnt++;
 }
 cout << cnt << endl;  
}