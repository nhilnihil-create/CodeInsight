#include<cstdio>
#include <vector>
#include <utility>
#include <functional>
#include<algorithm>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main(){
	int N, M;
	scanf("%d %d", &N, &M);
	unsigned A[N];
	for (int i = 0; i < N; ++i){
		scanf("%u", A + i);
	}
	sort(A, A + N);
	vector<pair<unsigned, unsigned> > B;
	for (int i = 0; i < M; ++i){
		unsigned tmp1, tmp2;
		scanf("%u %u", &tmp1, &tmp2);
		B.push_back(make_pair(tmp2, tmp1));
	}
	sort(B.begin() , B.end(), greater<pair<unsigned, unsigned> >());
	unsigned a_now = 0, b_now = 0;
	while(a_now < N && B[b_now].first > A[a_now]){
		unsigned i = 0;
		while(i < B[b_now].second && a_now < N && B[b_now].first > A[a_now]){
			A[a_now++] = B[b_now].first;
			i++;
		}
		if(i < B[b_now].second) break;
		b_now++;
	}
	ull ans = 0;
	for (int i = 0; i < N; ++i){
		ans += A[i];
	}
	printf("%llu\n", ans);
	return 0;
}