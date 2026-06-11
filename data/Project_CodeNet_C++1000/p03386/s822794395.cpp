#include <bits/stdc++.h>
using namespace std;

int main() {
	int a, b, k;
	scanf("%d %d %d", &a, &b, &k);
	set<int> st;
	for(int i = a; i < a + k; i++) {
		st.insert(i);
	}
	for(int i = b - k + 1; i <= b; i++) {
		st.insert(i);
	}
	for(auto itr = st.begin(); itr != st.end(); itr++) {
		if(*itr >= a && *itr <= b) {
			printf("%d\n", *itr);
		}
	}
}