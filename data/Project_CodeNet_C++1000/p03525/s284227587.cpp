#include<bits/stdc++.h>
using namespace std;

int n;
int li[14];
vector<int> ada;
vector<int> urut;
int main(){
	scanf("%d",&n);
	int ans = 15;
	for(int i=1;i<=n;i++){
		int x;
		scanf("%d",&x);
		li[x]++;
		ans = min(ans,x);
	}
	for(int i=1;i<=12;i++){
		if(li[i]>=3) ans = 0;
		else if(li[i] == 2){
			ada.push_back(i);
			ada.push_back(24-i);
		} else if(li[i] == 1){
			urut.push_back(i);
		}
	}
	int tmpa = 15;
	for(int i=0;i<ada.size();i++){
//		printf("> %d\n",ada[i]);
		for(int j=i+1;j<ada.size();j++){
			int lala = abs(ada[i] - ada[j]);
			tmpa = min(tmpa,min(lala,24-lala));
//			cout << tmpa << endl;
		}
	}
	int lala = -1;
	ans = min(ans,tmpa);
	for(int i=0;i<(1<<urut.size());i++){
		int curm = 15;
		for(int j=0;j<urut.size();j++){
			int cur;
			if(i & (1<<j)) cur = urut[j];
			else cur = 24-urut[j];
			for(int k=j+1;k<urut.size();k++){
				int now;
				if(i&(i<<k)) now = urut[k];
				else now = 24-urut[k];
				int dif = abs(cur-now);
				curm = min(curm,min(dif,24-dif));
			}
			for(int k=0;k<ada.size();k++){
				int dif = abs(cur-ada[k]);
				curm = min(curm,min(dif,24-dif));
			}
		}
		lala = max(lala,curm);
	}
	if(lala == -1) lala = 15;
	printf("%d\n",min(ans,lala));
  return 0;
}
