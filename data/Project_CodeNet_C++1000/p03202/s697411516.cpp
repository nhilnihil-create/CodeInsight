#include<bits/stdc++.h>
using namespace std;

int arr[200003] , N; vector < int > pot;

#define PII pair < int , int >
PII stk[200003]; int top;
bool check(int mid){
	top = 0;
	for(auto t : pot){
		while(top && stk[top].first > t) --top;
		auto add = [&](int x){
			if(top && stk[top].first == x) ++stk[top].second;
			else stk[++top] = PII(x , 1);
		};
		add(t);
		while(stk[top].first && stk[top].second == mid){--top; add(stk[top + 1].first - 1);}
		if(stk[top].first == 0) return 0;
	}
	return 1;
}

int main(){
	ios::sync_with_stdio(0); cin >> N;
	for(int i = 1 ; i <= N ; ++i) cin >> arr[i];
	for(int i = 2 ; i <= N ; ++i) if(arr[i] <= arr[i - 1]) pot.push_back(arr[i]);
	int L = 1 , R = N + 1;
	while(L < R){int mid = (L + R) >> 1; check(mid) ? R = mid : L = mid + 1;}
	cout << L; return 0;
}