#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
#include <vector>
#include <utility>
#include <map>
#define maxn 200005
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,a[maxn];
map <int,int> s;
typedef map<int,int> :: iterator Ite;
bool check(int x){
	s.clear();
	for(int i=1;i<=n;i++){
		if(a[i] > a[i - 1]) continue;
		Ite it = s.end();
		while(it != s.begin()){
			it--;
			if(it -> first > a[i]) s.erase(it);
			else break;
		}
		int pos = a[i];
		while(pos && s.find(pos) != s.end()){
			if(s[pos] < x - 1) break;
			s.erase(pos);
			pos--;
		}
		if(pos == 0) return false;
		s[pos]++;
	}
	return true;
}
int main(){
	scanf("%d",&n);
	bool ok1 = true;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(a[i] <= a[i - 1]) ok1 = false;
	}
	if(ok1){
		puts("1");
		return 0;
	}
	int lb = 2, rb = (int)1e9;
	while(lb < rb){
		int mid = (lb + rb) >> 1;
		if(check(mid)) rb = mid;
		else lb = mid + 1;
	}
	printf("%d\n",lb);
	return 0;
}
