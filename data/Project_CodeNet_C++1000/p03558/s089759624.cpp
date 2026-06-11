#include <iostream>
#include<cstdlib>
#include<queue>
#include<set>
#include<vector>
#include<string>
#include<algorithm>
#include<stack>
#include<map>
#include<deque>
#include<cstdio>
using namespace std;
#define rep(i,a) for(int i=0;i<a;i++)
#define mp make_pair
#define pb push_back
//#define ll __int64
#define ll long long
#define P pair<ll,ll>

int k;
deque<P>bfs;
bool v[200000];

int main(){
	cin>>k;
	bfs.push_back(mp(1,1));

	rep(i,1000000000){
		P tmp=bfs.front();
		bfs.pop_front();
		//cout<<tmp.first<<" "<<tmp.second<<endl;
		if(v[tmp.second])continue;
		v[tmp.second]=1;
		bfs.push_back(mp(tmp.first+1,(tmp.second+1%k)));
		bfs.push_front(mp(tmp.first,(tmp.second*10)%k));

		if(tmp.second%k==0){
				cout<<tmp.first<<endl;
				return 0;
		}
	}
	return 0;
}