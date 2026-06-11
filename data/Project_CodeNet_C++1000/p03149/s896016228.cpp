//do not think about past and stay in this moment
//organize and work - Abhinav IIITA
#include <bits/stdc++.h>
#include <ctime>
using namespace std;
#define int long long
#define ld long double
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end() 
const ld pi = acos(-1.0);
const int day[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());


// -----------------------------------------------------------------------

// -----------------------------------------------------------------------
int fre[10];
void solve(){
	int a,b,c,d;
	cin>>a>>b>>c>>d;
	fre[a]++;
	fre[b]++;
	fre[c]++;
	fre[d]++;
	if(fre[1]==1 && fre[4]==1 && fre[7]==1 && fre[9]==1)
	cout<<"YES";
	else
	cout<<"NO";	
	
}


// -----------------------------------------------------------------------


int32_t main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0); 	
	int t=1;
	//cin>>t;
	while(t--)
	solve();
	return 0;
}
