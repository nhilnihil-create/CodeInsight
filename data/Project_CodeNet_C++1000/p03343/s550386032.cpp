#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N,K,Q;
int A[100010];
int main(){
	cin >> N >> K >> Q;
	vector<int> v(N);
	for(int i=0;i<N;i++){
		cin >> A[i];
		v[i] = A[i];
	}
	sort(v.begin(),v.end());
	int ans = v[Q-1]-v[0];
	for(int i=0;i<N;i++){
		vector<int> removed,pre_removed;
		int c = 0;
		for(int j=0;j<=N;j++){
			if(j!=N && A[j]>v[i]){
				pre_removed.push_back(A[j]);
				c++;
			}else{
				if(c>=K){
					sort(pre_removed.begin(),pre_removed.end());
					for(int k=0;k<=c-K;k++){
						removed.push_back(pre_removed[k]);
					}
				}
				pre_removed.clear();
				c = 0;
			}
		}
		if(removed.size()>=Q){
			sort(removed.begin(),removed.end());
			ans = min(ans,removed[Q-1]-removed[0]);
		}
		removed.clear();
	}
	cout << ans << endl;
}
