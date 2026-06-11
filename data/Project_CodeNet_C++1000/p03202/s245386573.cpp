#include<bits/stdc++.h>
using namespace std;

int a[200001];

bool check(int x,int n){
	stack<pair<int,int> > st;
	st.emplace(0,0);
	st.emplace(1,a[1]);
	for(int i=2;i<=n;i++){
		if(a[i]>st.top().second)
			st.emplace(1,a[i]);
		else{
			while(st.top().second > a[i]){
				auto tp = st.top();st.pop();
				if(st.top().second < a[i])
					st.emplace(tp.first,a[i]);
			}
			while(st.top().first == x)
				st.pop();
			if(st.size()==1)	return false;
			auto tp = st.top();st.pop();
			if(tp.second - 1 != st.top().second)
				st.emplace(tp.first,tp.second-1);
			st.emplace(tp.first+1, tp.second);
			if(st.top().second != a[i])
				st.emplace(1,a[i]);
		}
	}
	return true;
}


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	int l=1,r=n;
	while(l<r){
		int mid = (l+r) >> 1;
		if(check(mid,n))
			r = mid;
		else
			l = mid+1;
	}
	cout<<l<<endl;
}
