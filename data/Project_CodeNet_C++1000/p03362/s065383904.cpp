#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<utility>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<functional>
#include<math.h>
using namespace std;
#define N (1000000000+7)
#define INF 1e16
typedef long long ll;
typedef pair<ll,ll> P;
 
bool prime[100001];
void furui() {
    prime[0]=true;
    prime[1]=true;
	int i = 2;
	while (i <= 100000) {
		int j = 2;
		while (j <= sqrt(i) && !prime[i]) {
			if (i%j == 0) {
				prime[i] = true;
				break;
			}
			else j++;
		}
		int z = 2;
		while (!prime[i]) {
			if (i*z <= 100000) {
				prime[i*z] = true;
				z++;
			}
			else break;
		}
		i++;
	}
}



int main(void){
    furui();
    int n;
    cin>>n;
    vector<int>ans;
    for(int i=2;i<=55555;i++){
        if(!prime[i]){
            if(i%5==1)ans.push_back(i);
        }
    }
    for(int i=0;i<n;i++){
        if(i==n-1)cout<<ans[i]<<endl;
        else cout<<ans[i]<<" ";
    }
    return 0;
}

