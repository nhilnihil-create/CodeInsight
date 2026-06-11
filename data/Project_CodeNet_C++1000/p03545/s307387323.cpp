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
  vector<int>num(4);
  rep(i,4) num[i]=s[i]-'0';
  for(int tmp=0;tmp<(1<<3);tmp++){
    int sum=num[0];
    string s;
    s=(char)('0'+num[0]);
    bitset<3>t(tmp);
    rep(i,3){
      if(t.test(i)){
        sum+=num[i+1];
        s+='+';
        s+=(char)('0'+num[i+1]);
      }
      else{
        sum-=num[i+1];
        s+='-';
        s+=(char)('0'+num[i+1]);
      }
    }
      if(sum==7){
        s+="=7";
        cout<<s<<endl;
        return 0;
      }
  }
}