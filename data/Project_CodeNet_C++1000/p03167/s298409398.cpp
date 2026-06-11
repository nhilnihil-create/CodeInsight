#include <bits/stdc++.h>
using namespace std;

typedef long double LD;
typedef long long ll;
typedef map<int,int> mii;
typedef pair<int,int> pii;
typedef vector<pii> vpii;

#define pb              push_back
#define mp              make_pair
#define F               first
#define S               second
#define INF             2147483647
#define endl            "\n"
#define FasterIO        ios_base::sync_with_stdio(0);cin.tie(0); cout.tie(0) ;
#define precision(a)    cout << fixed << setprecision(a)
#define bug(a,b)        cout<<a<<"\t"<<b<<"\n";
#define Case(a,b)       cout<<"Case "<<a<<": "<<b<<"\n";
#define reset(a,b)      memset(a,b,sizeof(a));
#define For(x,n)        for(int i=x; i<n; i++)

const int MAXN = 1000005;
const int SQRTN = 1003;
const int LOGN = 22;
const int mod = 1e9+7;
const double PI=acos(-1);

int strtoint(string str){
    stringstream ss(str);
    int x = 0;
    ss >> x ;
    return x ;
}
string intostr(int x){
    stringstream ss;
    ss << x;
    string str = ss.str();
    return str;
}
void rem(string &s, const string &c) {
	auto pos = s.find(c);
	if (pos == string::npos) {
		cout << -1 << endl;
		exit(0);
	}
	s.erase(0, pos + 1);
}
void println (int n){
    cout<<n<<"\n";
}
void printvec(vector <int> &a){
    for (int i=0;i<a.size();i++){
        cout<<a[i]<<" ";
    }
    cout<<"\n";
}

void printgraph(vector <int> g[],int e){
    for (int i=0;i<e;i++){
        cout<<i<<" --> ";
        for (int j=0;j<g[i].size();j++){
            cout<<g[i][j]<<" ";
        }
        cout<<"\n";
    }
}

void printmap (map <int,int> &mymap){
    for (auto itr = mymap.begin(); itr != mymap.end(); ++itr) {
        cout << '\t' << itr->first
             << '\t' << itr->second << '\n';
    }
    cout << "\n";
}

char grid[1005][1005];
int dp[1005][1005];


void solve(){
    int n,m;
    cin>>n>>m;
    for (int i=0;i<n;i++){
        cin>>grid[i];
    }

    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            if (grid[i][j]=='#')continue;

            if (i==0 && j==0){
                dp[i][j]=1;
                continue;
            }

            if (i>0)dp[i][j]+=dp[i-1][j];
            if (j>0)dp[i][j]+=dp[i][j-1];

            dp[i][j]=dp[i][j]%mod;
        }
    }
    cout<<dp[n-1][m-1]<<endl;

}


int main(){
    //FasterIO;

    solve();
    return 0;
}
