#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double D;
typedef pair<ll,ll> P;
#define M 1000000007
#define F first
#define S second
#define PB push_back
#define INF 100000000000000000
int n;
vector<int>b,ans;
int main(void){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
		int x;
		scanf("%d",&x);
		b.PB(x);
	}
    while(b.size()>0){
		bool ok=false;
		for(int i=b.size()-1;i>=0;i--){
			if(b[i]==i+1){
				ok=true;
				b.erase(b.begin()+i);
				ans.PB(i+1);
				break;
			}
		}
		if(!ok)break;
	}
	if(ans.size()!=n)printf("-1\n");
	else{
		for(int i=n-1;i>=0;i--)printf("%d\n",ans[i]);
	}
}
