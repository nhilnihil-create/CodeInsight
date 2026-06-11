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

int longestCommonSubsequence(string s1, string s2, vector<vector<int>>& dp) 
{
    for (int i = 1; i <= s1.size(); i++) 
    {
        for (int j = 1; j <= s2.size(); j++) 
        {
            if (s1[i-1] == s2[j-1]) 
                dp[i][j] = dp[i-1][j-1] + 1;

            dp[i][j] = max({dp[i][j], dp[i][j-1], dp[i-1][j]});
        }
    }
    return dp[s1.size()][s2.size()];
}

int main()
{
    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;
    cout.tie(NULL) ;
    
    string s1, s2; 
    cin >> s1 >> s2;

    vector<vector<int>> dp(s1.size()+1, vector<int>(s2.size()+1, 0));
    int count = longestCommonSubsequence(s1, s2, dp);   // This will give count of lcs and change the dp vector

    string s = "";
    int i = s1.size(), j = s2.size();
    while (i > 0 && j > 0) 
    {
        if (dp[i-1][j-1] + 1 == dp[i][j] && dp[i-1][j] + 1 == dp[i][j] && dp[i][j-1] + 1 == dp[i][j]) 
        {
            i--; 
            j--; 
            s = s1[i] + s; //As we are travelling backward reverse the string
        }
        else if (dp[i][j-1] > dp[i-1][j]) 
            j--;
        else
            i--;
    }
    cout << s << endl;

    return 0;
}