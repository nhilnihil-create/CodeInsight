#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <map>
#include <cmath>
#include <iomanip> 
#include <bits/stdc++.h>
using namespace std;
double pi=3.14159265358979323846264338;
const int MOD=1000000007;
vector<int>arr[100001];
vector<int>arr2[100001];
queue<int>que;
int cost;
int arr3[100001];
const int ad='A'-'a';

int main() {
	int n,m;
	cin>>n>>m;
	cost=0;
	for(int i=1;i<=m;i++){
		int a,b,c;
		cin>>a>>b>>c;
		
		arr[a].push_back(b);
		arr[b].push_back(a);
	}

	for(int i=1;i<=n;i++){
		if(!arr3[i]){
			arr3[i]=1;
			cost++;
			//cout<<i<<endl;
		}
		else continue;
		que.push(i);
		while(!que.empty()){
			int cur=que.front();
			que.pop();
			//cout<<cur<<" "<<i<<endl;
			for(auto c:arr[cur]){
				if(arr3[c])continue;
				arr3[c]=1;
				
				que.push(c);
			}
		}
	}
	
	cout<<cost<<endl;
  return 0;
}


