#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
typedef long long ll;
#define _GLIBCXX_DEBUG
typedef vector<int> vec;
typedef vector<ll> lvec;
typedef vector<char>cvec;
typedef pair<ll, ll> LP;
typedef tuple<ll, ll, ll> LT;
typedef pair<int, int> P;
typedef tuple<int, int, int> T;
int main()	{
  string s;
  cin>>s;
  if(s=="abc" || s=="acb"||s=="bac"||s=="bca"||s=="cab"||s=="cba")
    cout<<"Yes"<<endl;
  else
    cout<<"No"<<endl;
}