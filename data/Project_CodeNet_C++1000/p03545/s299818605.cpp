#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
typedef long long ll;
#define _GLIBCXX_DEBUG
typedef vector<int> vec;
typedef vector<ll> lvec;
typedef vector<char> cvec;
typedef vector<double> dvec;
typedef pair<ll, ll> LP;
typedef tuple<ll, ll, ll> LT;
typedef pair<int, int> P;
typedef tuple<int, int, int> T;
#define fs first
#define sc second
int main()	{
  string s;
  cin>>s;
  vector<int>a(4);
  rep(i,4) a[i]=s[i]-'0';
  for(int tmp=0;tmp<(1<<3);tmp++){
    bitset<4>t(tmp);
    int sum=a[0];
    string str;
    str+=(char)(a[0]+'0');
    rep(i,3){
      if(t.test(i)){
        str+='+';
        sum+=a[i+1];
      }
      else{
        str+='-';
        sum-=a[i+1];
      }
      str+=s[i+1];
    }
    if(sum==7){
      str+="=7";
      cout<<str<<endl;
      return 0;
    }
  }
  
}
        