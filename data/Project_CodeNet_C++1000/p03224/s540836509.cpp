#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=int(a);i<int(b);++i)
#define SIZE 100005
#define INF 1000000005LL
#define MOD 1000000007

using namespace std;
typedef long long int ll;
typedef pair <int,int> P;

int N;
vector<int> S[10000];

int main()
{
	cin >> N;
	int u=-1; //|Si| 集合数はu+1
	rep(i,1,10000){
		if(N == i*(i+1)/2){
			u = i;
			break;
		}
	}
	if(u==-1){
		cout << "No" << endl;
		return 0;
	}
	cout << "Yes" << endl;
	cout << u+1 << endl;
	int c = 1;
	rep(i,0,u){
		int t = u-i;
		rep(j,0,t){
			S[i].push_back(c);
			S[i+j+1].push_back(c);
			c++;
		}
	}
	rep(i,0,u+1){
		cout << u;
		rep(j,0,S[i].size()){
			cout << " ";
			cout << S[i][j];
		}
		cout << endl;
	}

	return 0;
}
