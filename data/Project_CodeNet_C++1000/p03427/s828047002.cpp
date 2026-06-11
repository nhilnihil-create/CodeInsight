#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define fo(a,b) for(int a=0;a<b;a++)
#define Sort(a) sort(a.begin(),a.end())
#define rev(a) reverse(a.begin(),a.end())
#define fi first
#define se second
#define bgn begin()
#define sz size()
#define en end()
#define pb push_back
#define pp() pop_back()
#define V vector
#define P pair
#define yuko(a) setprecision(a)
#define uni(a) a.erase(unique(a.begin(),a.end()),a.end())
#define Q queue
#define pri priority_queue
#define Pri priority_queue<int,vector<int>,greater<int>>
#define PriP priority_queue<P<int,int>,vector<P<int,int>>,greater<P<int,int>>>
#define all(a)  (a).begin(),(a).end()
#define ff first.first
#define fs first.second
#define sf second.first
#define ss second.second

int keta(int a){
  double b=a;
  b=log10(b);
  int c=b;
  return c+1;
}

signed main(){
  string s;
  cin >> s;
  if(s.size() == 1){
    cout << s << endl;
    return 0;
  }
  int a = s[0] - '0';
  string k = "";
  fo(i,s.size()-1){
    k.pb('9');
  }
  if(s.substr(1) != k){
    cout << (s.size()-1)*9 + a - 1 << endl;
  }
  else
    cout << (s.size() -1) * 9 + a << endl;
}