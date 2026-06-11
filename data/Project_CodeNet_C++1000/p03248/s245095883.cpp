#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> P;

#define fr first
#define sc second

int main(){
	string s;
	cin >> s;
	int n = s.size();
	//s = "1" + s;
	if(s[0] == '0' || s[n-1] == '1'){
		puts("-1");
		return 0;
	}
	vector<int> vec;
	for(int i = 0 ; i*2 <= n-2 ; i ++){
		if(s[i] != s[n-2-i]){
			puts("-1");
			return 0;
		}
		else if(s[i] == '1' && i > 0){
			vec.push_back(i);
		}
	}
	
	int v = 1,cnt = 1;
	for(int i = 0 ; i < vec.size() ; i ++){
		while(cnt <= vec[i]){
			printf("%d %d\n",cnt+1,v);
			cnt ++;
		}
		printf("%d %d\n",v,cnt+1);
		cnt ++;
		v = cnt;
	}
	for(int i = cnt+1 ; i <= n ; i ++){
		printf("%d %d\n",v,i);
	}
}

