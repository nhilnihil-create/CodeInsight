#include <bits/stdc++.h>
#define level first
#define cnt second
using namespace std;
typedef pair<int,int> ii;
 
int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	
	int n; cin >> n;
	int arr[n]; for(int i = 0;i < n;i++) cin >> arr[i];
	
	bool increasing = true;
	for(int i = 1;i < n;i++){
		if(arr[i] <= arr[i-1]) increasing = false;
	}
	
	if(increasing || n == 1){
		cout << 1;
		return 0;
	}
	
	int low = 1, high = n;
	while(low != high - 1){
		int mid = (low+high)/2;
		
		vector<ii> S = {ii(-1,0)};
		
		bool can = true;
		
		for(int i = 1;i < n;i++){
			
			if(arr[i-1] >= arr[i]){
				int cur = arr[i];
				
				while(S.back().level > cur) S.pop_back();
				
				while(true){
					if(S.back().level < cur){
						S.push_back(ii(cur,1));
						break;
					}
					else{
						S.back().cnt++;
						if(S.back().cnt == mid){
							S.pop_back();
							cur--;
							if(cur == 0){
								can = false;
								break;
							}
						}
						else{
							break;
						}
					}
				}				
			}
			
		}

		if(can) high = mid;
		else low = mid;
	}
	
	cout << high;
}
