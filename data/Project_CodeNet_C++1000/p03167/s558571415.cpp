#include<bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked
#define fo(i,n) for(i=0;i<n;i++)
#define Fo(i,k,n) for(i=k;k<n?i<n:i>n;k<n?i+=1:i-=1)
#define ll long long
#define ull unsigned long long
#define si(x)	scanf("%d",&x)
#define sl(x)	scanf("%lld",&x)
#define ss(s)	scanf("%s",s)
#define pi(x)	printf("%d\n",x)
#define pl(x)	printf("%lld\n",x)
#define ps(s)	printf("%s\n",s)
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define meme(x) memset(x, 0, sizeof(x))
#define sortall(x) sort(all(x))
#define tr(it, a) for(auto it = a.begin(); it != a.end(); it++)
#define PI 3.1415926535897932384626
#define mod 1'000'000'007
typedef pair<int, int>	pii;
typedef pair<ll, ll>	pl;
typedef vector<int>		vi;
typedef vector<ll>		vl;
typedef vector<pii>		vpii;
typedef vector<pl>		vpl;
typedef vector<vi>		vvi;
typedef vector<vl>		vvl;
mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
int rng(int lim) {
	uniform_int_distribution<int> uid(0,lim-1);
	return uid(rang);
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());
    int h,w,i,j;
    cin>>h>>w;
    char arr[h][w];
    fo(i,h){
        fo(j,w){
            cin>>arr[i][j];
        } 
    } 
    ll dp[h][w];
    dp[0][0]=1;
    Fo(i,1,h){
        if(arr[i][0]=='#'){
            dp[i][0] = 0;
        }else{
            dp[i][0] = dp[i-1][0];
        }
    }
    Fo(i,1,w){
        if(arr[0][i]=='#'){
            dp[0][i] = 0;
        }else{
            dp[0][i] = dp[0][i-1];
        }
    }
    Fo(i,1,h){
        Fo(j,1,w){
            if(arr[i][j]=='#'){
                dp[i][j]=0;
            }else{
                dp[i][j]=(dp[i-1][j]+dp[i][j-1])%mod;
            }
        }
    }
    cout<<(dp[h-1][w-1])%mod<<"\n";
}
