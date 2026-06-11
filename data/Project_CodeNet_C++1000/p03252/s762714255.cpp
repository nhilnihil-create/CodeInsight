#include <iostream>
#include <utility>
#include <map>
#include <vector>
#include <algorithm>
#include <queue>
#include <math.h>
#include <stack>
#include <set>
#include <deque>
#include <cmath>
#include <cassert>

using namespace std;
typedef long long ll;
ll mod = 1e9+7;
#define rep(i,n) for(int i = 0; i < (n); ++i)

vector<int> v,vv;
int pre[26];
 
int main()
{
	rep(i,26) pre[i]=-1;
	string s,t;
	cin>>s>>t;
 
	rep(i,(int)s.size()){
		v.push_back(pre[s[i]-'a']);
		pre[s[i]-'a']=i;
	}
 
	rep(i,26) pre[i]=-1;
	rep(i,(int)t.size()){
		if(pre[t[i]-'a']!=v[i]){
			cout<<"No\n";
			return 0;
		}
		pre[t[i]-'a']=i;
	}
	cout<<"Yes\n";
 
 
	return 0;
}