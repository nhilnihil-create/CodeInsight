#include <bits/stdc++.h>
using namespace std;

#define FLASH ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define int long long
#define ld long double
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define vpp vector<pair< int, int > >  
#define pll pair<int , int >
#define ppll pair < pll , pll >
#define debug(n1) cout << n1 << endl
#define len(a) ((int) (a).size())
#define endl "\n"

int32_t main()
{
 FLASH;
 int n,m,x;
 cin>>n>>m>>x;
 int arr[m];
 for(int i=0;i<m;i++)
 {
 	cin>>arr[i];
 }
 int cnt=0,cnt1=0;
 for(int i=0;i<m;i++)
 {
 if(arr[i]<x){cnt++;}
 if(arr[i]>x){cnt1++;} 
 
 }
 cout<<min(cnt,cnt1)<<endl;
}

