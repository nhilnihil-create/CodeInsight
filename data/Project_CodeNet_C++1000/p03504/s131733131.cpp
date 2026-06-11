#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	int N, C;
	cin>>N>>C;
	int s[N], t[N], c[N];
	vector<vector<int> >tmpschedule;
	vector<int>tmparr;
	for(int i=0;i<C;++i){
		tmpschedule.push_back(tmparr);
	}

	for(int i=0;i<N;++i){
		cin>>s[i]>>t[i]>>c[i];
		c[i]--;
	}
	for(int i=0;i<N;++i){
		tmpschedule[c[i]].push_back(s[i]);
		tmpschedule[c[i]].push_back(t[i]);
	}
	for(int i=0;i<C;++i){
		sort(tmpschedule[i].begin(), tmpschedule[i].end());
	}

	vector<vector<int> >schedule;
	for(int i=0;i<C;++i){
		schedule.push_back(tmparr);
	}

	int j;
	int size;
	for(int i=0;i<C;++i){
		j = 0;
		while(true){
			size = tmpschedule[i].size();
			if(j >= size-1) break;
			if(tmpschedule[i][j]==tmpschedule[i][j+1])j+=2;
			else {
				schedule[i].push_back(tmpschedule[i][j]);
				j++;
			}
		}
		if(tmpschedule[i].size()>0){
			schedule[i].push_back(tmpschedule[i][j]);
		}
	}
	/**
	for(int i=0;i<C;++i){
		for(int j=0;j<schedule[i].size();++j){
			cout<<schedule[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
	**/
	vector<pair<int, int> > tvschedule;
	for(int i=0;i<C;++i){
		for(int j=0;j<schedule[i].size();++j){
			if(j % 2 == 0){
				tvschedule.push_back(make_pair(schedule[i][j], 0));
			}
			else{
				tvschedule.push_back(make_pair(schedule[i][j], 1));
			}
		}
	}
	sort(tvschedule.begin(), tvschedule.end());
	int usetv = 0;
	int ans = 0;
	for(int i=0;i<tvschedule.size();++i){
		if(tvschedule[i].second == 0) usetv++;
		else usetv--;
		if(ans < usetv)ans = usetv;
	}
	cout<<ans<<endl;
}
