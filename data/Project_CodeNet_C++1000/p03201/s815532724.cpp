#include <bits/stdc++.h>

#define PI 3.14159265358979323846264338327950288419

using namespace std;

map<int, int> freq;
int n, a[200005];

int f(int x){
	int ret = 1;
	while(ret <= x){
		ret *= 2;
	}
	return ret - x;
}

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
		if(!freq.count(a[i])){
			freq[a[i]] = 1;
		}else{
			freq[a[i]]++;
		}
	}
	
	// observation: the largest number only has one choice
	sort(a + 1, a + n + 1);
	int ans = 0;
	for(int i = n; i >= 1; i--){
		int cur_num = a[i];
		while(freq[cur_num] > 0){
			freq[cur_num]--;
			int choose = f(cur_num);
			if(freq[choose] > 0){
				freq[choose]--;
				ans++;
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}
