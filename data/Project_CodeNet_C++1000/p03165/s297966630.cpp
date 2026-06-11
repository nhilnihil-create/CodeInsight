#include<bits/stdc++.h>
using namespace std;
char s1[4000],s2[4000],s3[4000];
vector<int> lis(vector<int>&v, int &ans){
	int n = v.size();
	int inf = INT_MAX;
	vector<int> d(n+2,inf);
	d[0] = -inf;
	vector<int> id(n+1),pre(n+1);
	for(int i = 0; i < n; i++){
		int j = upper_bound(d.begin(), d.end(), v[i]) - d.begin();
		if(d[j-1] < v[i]){
			d[j] = v[i];
			pre[i] = id[j-1];
			id[j] = i;
		}
	}
	ans = upper_bound(d.begin(),d.end(),inf-1) - d.begin();
	ans--;
	vector<int> sec(ans);
	int j = id[ans];
	for(int i = ans-1; i >= 0; i--){
		sec[i] = v[j];
		j = j = pre[j];
	}
	return sec;
}
int main(){
	scanf("%s %s",s1,s2);
	int a,b;
	a = strlen(s1); b=strlen(s2);
	vector<vector<int> > gr(a);
	int tot=0;
	for(int i = b-1; i >=0; i--){
		for(int j = 0; j < a; j++)
			if(s1[j] == s2[i]){
				gr[j].push_back(i);
				tot++;
			}
	}
	vector<int> v;
	v.reserve(tot);
	for(int i = 0; i < a; i++)
		for(int x : gr[i])
			v.push_back(x);
	int k;
	vector<int>sec=lis(v,k);
	s3[k] = 0;
	for(int i = 0; i < k; i++)
		s3[i] = s2[sec[i]];
	printf("%s\n",s3);
	return 0;
}