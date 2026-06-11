#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<utility>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<functional>
#include<math.h>
using namespace std;
#define N (1000000000+7)
//#define N (998244353)
#define INF 1e16
typedef long long ll;
typedef pair<ll,ll> P;
typedef vector<ll> vec;
typedef vector<vec> mat;

const int inf = 1e9;

ll dp[1000010][4];

char s[305][305];

int main(void){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>s[i][j];
        }
    }
    int ans = 0;
    for(int i=0;i<n;i++){
        int a = 0;
        int b = i;
        bool flag = true;
        for(int j=0;j<n;j++){
            for(int k=j;k<n;k++){
                int i1 = (j+a)%n;
                int j1 = (k+b)%n;
                int i2 = (k+a)%n;
                int j2 = (j+b)%n;
                flag = flag&(s[i1][j1]==s[i2][j2]);
            }
        }
        if(flag)ans+=n;
    }
    cout<<ans<<endl;
}