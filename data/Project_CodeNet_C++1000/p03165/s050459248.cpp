#include<bits/stdc++.h>
#define fo(i,a,b) for(int i= a ; i < b ; ++i)
#define rep(i,n) fo(i,0,n)
#define pln(n) printf("%lld\n",n)
#define sll(n) scanf("%lld",&n)
#define ss(n) scanf("%s",n)
#define vi vector < int >
#define pii pair < int , int >
#define pb push_back
#define mp make_pair
#define ll long long
#define ull unsigned long long
#define INF 0x3f3f3f3f
#define dbg(x) { cout<< #x << ": " << (x) << endl; }
#define dbg2(x,y) { cout<< #x << ": " << (x) << " , " << #y << ": " << (y) << endl; }
#define dbg3(x,y,z) { cout<< #x << ": " << (x) << " , " << #y << ": " << (y) <<" , "<< #z <<": "<<(z)<<endl; }
#define all(x) x.begin(),x.end()
#define sz(x) (int)x.size()
#define vll vector<long long>
#define vvi vector<vector<int>>
#define si set<int>
#define tr(c, it) \
for(decltype(c.begin()) it = c.begin(); it!= c.end(); it++)
#define pis pair<int,string>
#define present(c, x) (c.find(x) != c.end())
#define cpresent(c, x) (find(all(c),x) != c.end())
using namespace std;
int main(){
    string a, b;
    cin >> a >> b;
    int m = a.size();
    int n = b.size();
    int L[m+1][n+1];
    for(int i = 0; i <= m; i++){
    	L[i][0] = 0;
    }
    for(int i = 0; i <= n; i++){
    	L[0][i] = 0;
    }
    for(int i = 1; i <= m; i++){
    	for(int j = 1; j <= n; j++){
    		if(a[i-1] == b[j-1]){
    			L[i][j] = L[i-1][j-1] + 1;
    		}
    		else{
    			L[i][j] = max(L[i-1][j], L[i][j-1]);
    		}
    	}
    }
    int i = m;
    int j = n;
    string ans = "";
    while(i > 0 && j > 0){
    	if(a[i-1] == b[j-1]){
    		ans += a[i-1];
    		i--;
    		j--;
    		continue;
    	}
    	if(L[i][j] == L[i-1][j]){
    		i--;
    	}
    	else if(L[i][j] == L[i][j-1]){
    		j--;
    	}
    	else{
    		i--;
    		j--;
    	}
    }
    reverse(ans.begin(), ans.end());
    cout << ans << endl;

}