#include <bits/stdc++.h>
#include <iostream>
#include<set>
#include<utility>
using namespace std;
#include<algorithm>
#define ll  long long
#define M1 1000000007
#define M2 998244353
#define pll pair<ll,ll>
#define fori(i,n) for(ll i=0;i<n;i++)
#define forj(j,m) for(ll j=0;j<m;j++)
#define vecti vector<ll int >
#define vectp vector<pair<ll int, ll int > >
#define MOD 1000000007
#define fast() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define MAXN   100001
#define pb push_back
#define m_p make_pair
//const int N = 2e5 + 5;
/*l int pow(ll int n){
ll int sum=0;
ll int x=1;

for(ll int i=1;i<n;i++){

    x=x*2;

}
return x;


}*/
//ll int dp[100005][2];

/*void rvereseArray(ll int arr[],ll int start, ll int end)
{
    if (start >= end)
    return;

   ll int temp = arr[start];
    arr[start] = arr[end];
    arr[end] = temp;

    // Recursive Function calling
    rvereseArray(arr, start + 1, end - 1);
}*/



int32_t main()
{
	fast();
	ll int t;
	//cin >> t;
	t=1;
	while(t--)
	{
	    ll int n,k;
	    cin>>n>>k;
	    vecti a(n);
	    fori(i,n){
	    cin>>a[i];
	    }
	    sort(a.begin(),a.end());
          bool dp[100003]={false};
          for(ll int i=0;i<n;i++){
            dp[a[i]]=true;
          }
          for(ll int i=0;i<=k;i++){
                for(ll int j=0;j<n;j++){
                    if(a[j]<=i){
                        if(!dp[i-a[j]]){
                            dp[i]=true;
                        }
                    }
                }


          }
          if(dp[k]){
            cout<<"First"<<endl;
          }
        else{
            cout<<"Second"<<endl;
        }


}

 }
