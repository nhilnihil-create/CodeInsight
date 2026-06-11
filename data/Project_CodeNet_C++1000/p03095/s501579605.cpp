#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<utility>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<math.h>
using namespace std;
#define mod (1000000000+7)
#define N (10007)
#define INF 1e16
typedef long long ll;
typedef pair<int,int> P;



int main(void){
    ll n;
    string s;
    cin>>n>>s;
    map<char,ll>m;
    for(int i=0;i<n;i++)m[s[i]]++;
    ll ans = 1;
    for(auto itr = m.begin();itr!=m.end();++itr){
        ans = (ans*(itr->second+1))%mod;
    }
    cout<<(ans-1+mod)%mod<<endl;
	return 0; 
}