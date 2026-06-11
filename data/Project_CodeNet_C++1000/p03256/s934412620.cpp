#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=int(a);i<int(b);++i)
#define SIZE 200005
#define INF 1000000005LL
#define MOD 1000000007

using namespace std;
typedef long long int ll;
typedef pair <int,int> P;

int N,M;
int A[SIZE],B[SIZE];
vector<int> G[SIZE];
string S;

int main()
{
	cin >> N >> M >> S;
	rep(i,0,M){
		int a,b;
		cin >> a >> b;
		G[a].push_back(b);
		G[b].push_back(a);
		if(S[b-1]=='A'){
			A[a]++;
		}else{
			B[a]++;
		}
		if(S[a-1]=='A'){
			A[b]++;
		}else{
			B[b]++;
		}
	}
	int cnt = 0;

	queue<int> Q;
	rep(i,1,N+1){
		if(A[i]==0 || B[i]==0){
			Q.push(i);
			cnt++;
		}
	}

	while(!Q.empty()){
		int v = Q.front();Q.pop();
		for(int c : G[v]){
			if(S[v-1]=='A'){
				A[c]--;
				if(A[c]==0 && B[c]>0){
					Q.push(c);
					cnt++;
				}
			}else{
				B[c]--;
				if(B[c]==0 && A[c]>0){
					Q.push(c);
					cnt++;
				}
			}
		}
	}
	if(N != cnt){
		cout << "Yes" << endl;
	}else{
		cout << "No" << endl;
	}

	return 0;
}
