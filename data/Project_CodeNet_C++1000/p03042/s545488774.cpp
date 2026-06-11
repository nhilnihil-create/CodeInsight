#include<bits/stdc++.h>
using namespace std;
#define ff      first
#define ss      second
#define ll      int
#define ull     unsigned long long
#define mod     1000000007
#define vi      vector<ll>
#define ppi     pair<ll,pair<ll,ll>>
#define pb      push_back
#define mp      make_pair
#define str     string
#define pi      2*acos(0.0)
#define pr(a,x,n) for(int i=x;i<n;i++){cout<<a[i]<<" ";}
#define p(a)    cout<<a;
#define sp(x,y) fixed<<setprecision(y)<<x
#define w(x)    ll x; cin>>x; while(x--)
#define e       cout<<'\n';
#define all(v)  v.begin(), v.end()
#define test    cout<<"BECOME_EXPERT_FAST"<<endl;
void kehsihba(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	/*#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif*/
}
int32_t main() {
	kehsihba();
	int a;scanf("%d",&a);
	int L=a/100;
	int R=a%100;
	if(1<=L&&L<=12){
	if(1<=R&&R<=12)printf("AMBIGUOUS\n");
	else printf("MMYY\n");
	}else{
	if(1<=R&&R<=12)printf("YYMM\n");
	else printf("NA\n");
	}
}





