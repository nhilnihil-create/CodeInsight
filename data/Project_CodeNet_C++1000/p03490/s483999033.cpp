#include <iostream>
#include <vector>
using namespace std;
#define debug(x) std::cerr << #x << " = " << (x) << std::endl
typedef long long LL;
const int MAXN = 8e3+17;
string str;
bool can = false;
int a,b;
vector<pair<int,int > > vec;
bool dp[2][2][MAXN*2];
int main(int argc ,char const *argv[])
{
    #ifdef GoodbyeMonkeyKing
    freopen("Input.txt","r",stdin);freopen("Output.txt","w",stdout);
    #endif
    cin>>str;
    cin>>a>>b;
    for (int i = 0; i <= 16000; ++i)
    	dp[0][0][i]=dp[0][1][i]=dp[1][0][i]=dp[1][1][i]=false;
    int k = 0,tmp = 0;
    for (int i = 0; i < str.length(); ++i)
    {
    	if(str[i]=='T')
    	{
    		vec.push_back({tmp,k&1});
    		k++;
    		tmp=0;
    	}
    	else
    		tmp++;
    }
    vec.push_back({tmp,k&1});
    int nx = 0,px = 1,ny = 0,py = 1;
    dp[0][0][8000] = dp[0][1][8000] = 1;
    for (int i = 0; i < vec.size(); ++i)
    {
    	if(vec[i].second)
    	{
    		swap(ny,py);
    		for (int j = 0; j <= 16000; ++j)
    			dp[ny][1][j] = false;
    		for (int j = 0; j <= 16000; ++j)
    		{
    			if(dp[py][1][j])
    			{
    				if(j-vec[i].first>=0)
    					dp[ny][1][j-vec[i].first] = 1;
    				if(j+vec[i].first<=16000)
    					dp[ny][1][j+vec[i].first] = 1;
    			}
    		}
    	}
    	else
    	{
    		swap(nx,px);
    		for (int j = 0; j <= 16000; ++j)
    			dp[nx][0][j] = false;
    		for (int j = 0; j <= 16000; ++j)
    		{
    			if(dp[px][0][j])
    			{
    				if(i>0&&(j-vec[i].first>=0))
    					dp[nx][0][j-vec[i].first] = 1;
    				if(j+vec[i].first<=16000)
    					dp[nx][0][j+vec[i].first] = 1;
    			}
    		}
    	}
    }
    if(dp[nx][0][a+8000]&&dp[ny][1][b+8000])
    	cout<<"Yes"<<endl;
    else
    	cout<<"No"<<endl;
    return 0;
}
