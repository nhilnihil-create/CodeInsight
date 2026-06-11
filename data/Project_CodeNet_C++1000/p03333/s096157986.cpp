#include <bits/stdc++.h>

#define PI 3.14159265358979323846264338327950288419

using namespace std;

int n, l[100005], r[100005];
bool visited[100005];
int pos;
long long ans;

pair<int, int> left_pts[100005];
pair<int, int> right_pts[100005];
int left_ptr, right_ptr;

void go_left(int &pos, long long &cans){
	while(true){
		pair<int, int> cur = right_pts[right_ptr];
		if(visited[cur.second]){
			right_ptr++;
		}else{
			if(pos > cur.first){
				cans += pos - cur.first;
				pos = cur.first;
			}
			visited[cur.second] = true;
			return;
		}
	}
}

void go_right(int &pos, long long &cans){
	while(true){
		pair<int, int> cur = left_pts[left_ptr];
		if(visited[cur.second]){
			left_ptr--;
		}else{
			if(pos < cur.first){
				cans += cur.first - pos;
				pos = cur.first;
			}
			visited[cur.second] = true;
			return;
		}
	}
}

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		scanf("%d %d", &l[i], &r[i]);
		left_pts[i] = {l[i], i};
		right_pts[i] = {r[i], i};
	}
	sort(left_pts + 1, left_pts + n + 1);
	sort(right_pts + 1, right_pts + n + 1);
	
	// LRLR...
	long long ans1 = 0;
	memset(visited, false, sizeof(visited));
	pos = 0;
	left_ptr = n;
	right_ptr = 1;
	for(int i = 1; i <= n; i++){
		if(i & 1){
			go_left(pos, ans1);
		}else{
			go_right(pos, ans1);
		}
	}
	ans = ans1 + abs(pos);
	
	// RLRL...
	
	long long ans2 = 0;
	memset(visited, false, sizeof(visited));
	pos = 0;
	left_ptr = n;
	right_ptr = 1;
	for(int i = 1; i <= n; i++){
		if(i & 1){
			go_right(pos, ans2);
		}else{
			go_left(pos, ans2);
		}
	}
	ans = max(ans, ans2 + abs(pos));
	
	printf("%lld\n", ans);
	return 0;
}