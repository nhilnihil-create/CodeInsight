#include <bits/stdc++.h> 
using namespace std;

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	vector<int> L,R;
	vector<long long> K(1,0);
	int N; cin>>N;
	for(int i=0;i<N;i++){ int l,r; cin>>l>>r; L.push_back(l); R.push_back(-r); }
	sort(L.begin(),L.end());
	sort(R.begin(),R.end());
	while(!L.empty()){
		int l=L.back(); 
		int r=R.back();
		L.pop_back();
		R.pop_back();
		if(l+r>=0){
			if(min(l,r)>=0) K.front()+=l+r; 
			else{ K.push_back(max(l,r)+K.front()); K.front()+=l+r; }
		}
		else{
			K.front()+=max({0,l,r});
			break;
		}
	}
	long long res=0;
	while(!K.empty()){
		res=max(res,K.back());
		K.pop_back();
	}
	cout<<res*2<<endl;
	return 0;
}