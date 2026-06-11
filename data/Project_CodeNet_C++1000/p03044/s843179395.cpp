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
int arr3[100001];
const int ad='A'-'a';

int main() {
	int n;
	cin>>n;
	for(int i=1;i<n;i++){
		int a,b,c;
		cin>>a>>b>>c;
		if(!(c%2)){
			//cout<<a<<b<<c<<endl;
			arr[a].push_back(b);
			arr[b].push_back(a);
		}
		else{
			//cout<<a<<b<<c<<c%2<<endl;
			arr2[a].push_back(b);
			arr2[b].push_back(a);
		}
	}
	que.push(1);
	arr3[1]=1;
	while(!que.empty()){
		int cur=que.front();
		que.pop();
		for(auto c:arr[cur]){
			if(!arr3[c]){
				arr3[c]=arr3[cur];
				que.push(c);
				//cout<<arr3[c]<<" "<<cur<<" "<<arr3[cur]<<endl;
			}
		}
		for(auto c:arr2[cur]){
			if(!arr3[c]){
				arr3[c]=3-arr3[cur];
				que.push(c);
			}
		}
	}
	for(int i=1;i<=n;i++){
		cout<<arr3[i]-1<<endl;
	}
  return 0;
}


