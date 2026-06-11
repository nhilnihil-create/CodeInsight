#include<iostream>
#include<map>
using namespace std;
int n;
int a[200001];
map<int,int>m;
bool can(int mid){
	m.clear();
	for(int i=1; i<=n ;i++){
		if(a[i]>a[i-1]) continue;
		auto it=m.end();
		while(!m.empty()){
			--it;
			if(it->first<=a[i]) break;
			m.erase(it);
			it=m.end();
		}
		m[a[i]]++;
		int cur=a[i];
		while(cur>0 && m[cur]==mid){
			m.erase(cur);
			m[--cur]++;
		}
		if(cur==0) return false;
	}
	return true;
}
int main(){
	ios::sync_with_stdio(false);
	cin >> n;
	bool flag=true;
	for(int i=1; i<=n ;i++){
		cin >> a[i];
		if(i>1 && a[i]<=a[i-1]) flag=false;
	}
	if(flag){
		cout << "1\n";
		return 0;
	}
	int l=2,r=3e5,mid;
	while(l!=r){
		mid=(l+r)/2;
		if(can(mid)) r=mid;
		else l=mid+1;
	}
	cout << l << endl;
}