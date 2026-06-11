#include <iostream>
#include<vector>
using namespace std;

int main() {
	int k;cin>>k;
//	vector<vector<int>> v(k);
	vector<int> list,next;
	int ans=1;
	int flag=0;
	int used[k];
	for(int i=0;i<k;i++){
		used[i]=0;
	}
	list.push_back(1);
	while(1){
		while(list.size()){
			int num=list.back();
//			cout<<num<<endl;
			if(num==0){
					flag=1;
					break;
			}
			list.pop_back();
			if(used[num]==0){
				used[num]=1;
				next.push_back((num+1)%k);
				list.push_back((num*10)%k);
			}

		}
		if(flag){
			break;
		}
		list=next;
		next.clear();
		ans++;
	}
	cout<<ans<<endl;

	return 0;
}
