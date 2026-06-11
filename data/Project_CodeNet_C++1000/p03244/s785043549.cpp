#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pi;
int counter1[100005];
int counter2[100005];
int len1,len2;
int main(){
	int n;
	cin>>n;
	if(n%2){
		len1 = n/2+1;
		len2 = n/2;
	}
	else{
		len1 = n/2;
		len2 = n/2;
	}
	vector<int>arr(n);
	for(int i=0; i<n; i++) cin>>arr[i];
	for(int i=0; i<n; i+=2) counter1[arr[i]]++;
	for(int i=1; i<n; i+=2) counter2[arr[i]]++;
	priority_queue<pi,vector<pi>, greater<pi> >pq1;
	priority_queue<pi,vector<pi>, greater<pi> >pq2;
	for(int i=1; i<=100000; i++){
		if(counter1[i]){
			pq1.push(pi(len1-counter1[i],i));
		}
	}
	for(int i=1; i<=100000; i++){
		if(counter2[i]){
			pq2.push(pi(len2-counter2[i],i));
		}
	}
	int change1 = pq1.top().first;
	int v1 = pq1.top().second;
	int change2 = pq2.top().first;
	int v2 = pq2.top().second;
	pq1.pop();
	pq2.pop();
	if(v1!=v2) cout<<change1+change2;
	else{
		int c1,c2;
		if(pq1.empty()) c1 = len1;
		else c1 = pq1.top().first;
		if(pq2.empty()) c2 = len2;
		else c2 = pq2.top().first;
		cout<<min(change1+c2,c1+change2);
	}
}