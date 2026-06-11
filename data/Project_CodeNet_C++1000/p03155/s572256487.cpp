#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <utility>
#include <climits>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int INF=1<<29;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int N,H,W;
	cin>>N>>H>>W;
	cout<<(N-H+1)*(N-W+1)<<endl;
	return 0;
}