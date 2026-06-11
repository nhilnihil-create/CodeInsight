#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define rep(i,n) for(int i=0;i<(n);i++)
#define reps(i,n,s) for(int i=(s);i<(n);i++)
typedef long long int ll;
using namespace std;
using Graph = vector<vector<int> >;

int main(){
cin.tie(0);
ios::sync_with_stdio(false);
int N,K;
cin>>N>>K;
int ans;
if(N%K==0)ans=0;
else ans=1;
cout<<ans<<endl;

//system("pause");
return 0;
}