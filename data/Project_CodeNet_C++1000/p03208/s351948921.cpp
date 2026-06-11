
#include <bits/stdc++.h>
#include <string.h>
#include <vector>
//s#define rep(i, n) for (int i = 0; i < (n); i++)
#define MAX 10000

using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair
#define all(a) (a).begin(),(a).end()
#define rep(i,a,n) for(int i=a; i<n; i++)
#define r0 return 0
#define INF (int)1e15
#define MOD 1000000007

int main(){

int n,k;
cin>>n>>k;

vector<int>h(n);
for(int i=0;i<n;i++)
 cin>>h.at(i);

 sort(h.begin(),h.end());

 int index = 0,ans = INT_MAX;

 for(int i=k-1;i<n;i++){

    int memo = h[i] - h[index];
    ans = min(ans,memo);
    index++;
 }

  cout<<ans<<endl;


return 0;
}
