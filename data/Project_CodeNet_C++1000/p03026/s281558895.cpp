#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <string>
#include <iomanip>
using namespace std;
int n;
int a[10000],b[10000];
vector<int> c;
vector<int> ch[10000];
int ans[10000];
int cnt=0;
void dfs(int now){
	ans[now]=c[cnt];
	cnt++;
	for(int i=0;i<ch[now].size();i++){
		if(ans[ch[now][i]]==0){
			dfs(ch[now][i]);
		}
	}
}
int main(){
	cin>>n;
	for(int i=0;i<n-1;i++){
		cin>>a[i]>>b[i];
		a[i]--;
		b[i]--;
		ch[a[i]].push_back(b[i]);
		ch[b[i]].push_back(a[i]);
	}
	for(int i=0;i<n;i++){
		int d;
		cin>>d;
		c.push_back(d);
	}
	sort(c.rbegin(),c.rend());
	int sum=0;
	for(int i=1;i<n;i++){
		sum+=c[i];
	}
	cout<<sum<<endl;
	dfs(0);
	for(int i=0;i<n;i++){
		cout<<ans[i];
		if(i==n-1){
			cout<<endl;
		}else{
			cout<<" ";
		}
	}
	return 0;
}
