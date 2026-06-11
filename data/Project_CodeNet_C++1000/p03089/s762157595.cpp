#include<bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	vector<int> v(n+1);
	v[0]=-1;
	vector<int> ans;
	for(int i=1;i<=n;i++)
		cin>>v[i];
	for(int i=n;i>=1;i--){
		int j;
		for(j=i;j>=1;j--){
			if(j==v[j]){
				ans.emplace_back(j);
				v.erase(v.begin()+j);
				break;
			}
		}
		if(j==0){
			cout<<-1<<endl;
			return 0;
		}
	}
	reverse(ans.begin(),ans.end());
	for(int it:ans)
		cout<<it<<endl;
}
