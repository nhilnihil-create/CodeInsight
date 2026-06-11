#include<algorithm>
#include<iostream>
#include<vector>
#include<string>
#include<cstring>
#include<utility>
#include<queue>
#include<cmath>
using namespace std;
#define REP(i, a,b) for(i=a;i<b;i++) 
#define REP1(i,b,a) for(i=b-1;i>=a;i--)
#define output(x) cout<<x<<endl;
#define pb(x) push_back(x);
typedef long long int ll;
const int MAX = 510000;
const int MOD = 1000000007;


int main()
{
	ll i, j, k, l, m, sum, flag, N, M;
	sum = 0;
	flag = 0;
	cin >> N;
  if(N==1){
  output("Yes");
    output(2);
    cout<<1<<" "<<1<<endl;
    cout<<1<<" "<<1<<endl;
    return 0;
  }
	ll s[500][500];
	REP(i, 1, N*2) {
		if (i*(i - 1) == 2*N) {
			flag = 1;
			break;
		}
	}
	k = i;
	if (flag == 0) {
		output("No");
	}
	else {
		output("Yes");
		output(k);
		ll z;
		z = 1;
		REP(i, 1, k + 1) {
			REP(j, 0, k - i) {
				s[i][j + i] = z;
				s[i + j+1][i] = z;
				z++;
			}
		}
		
		REP(i, 1, k + 1) {
			cout << k - 1 << " ";
			REP(j, 1, k) {
				cout << s[i][j] << " ";
			}
			cout << endl;
		}
	}
    return 0;
}

