#include<iostream>
#include<string>
#include<string.h>
#include<cstring>
#include<math.h>
#include<iomanip>
#include<vector>
#include<cmath>
#include<algorithm>
#include<numeric>
#include<cctype>
#include<utility>
#include<set>
#include<map>
#include<sstream>
#include<iterator>
#include<limits>
#include<map>
#include<deque>
#include<stack>
#include<queue>
using namespace std;
#define pb push_back
#define ff(i,a,b) for(int i=a;i<b;++i)
#define ffl(i,a,b) for(long long i=a;i<b;++i)
#define all(v) v.begin(), v.end() 
#define X first
#define Y second
#define mp make_pair
typedef long long ll;
typedef std::vector<int> vec;
typedef std::vector<long long> vecl;
typedef map<int,int> mii;
typedef map<ll,ll> mll;
typedef std::pair<int,int> pii;
typedef pair<ll,ll> pll; 
const int md = 1000000007;
#define pi 3.141592653589793238462643383279


int main() {
	ios_base::sync_with_stdio(false); 
    cin.tie(NULL);    
    
 	int tt{},T{};
 	//cin>>tt;T=tt;
    tt=1;
 	while(tt--){
        //cout<<"------------- #"<<T-tt<<endl;
        int n{},m{},ans{},k{},a{},b{},c{},f{};
        
        cin>>n;
        int dp[n][3]{};
        cin>>a>>b>>c;
        dp[0][0]=a;
        dp[0][1]=b;
        dp[0][2]=c;
        ff(i,1,n){
            cin>>a>>b>>c;
            dp[i][0]=max(dp[i-1][1],dp[i-1][2])+a;
            dp[i][1]=max(dp[i-1][0],dp[i-1][2])+b;
            dp[i][2]=max(dp[i-1][0],dp[i-1][1])+c;
        }
        cout<<max(dp[n-1][0],max(dp[n-1][1],dp[n-1][2]))<<"\n";
    }
    
    
	return 0;
}