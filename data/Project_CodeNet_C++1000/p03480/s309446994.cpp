#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<utility>
#include<map>
#include<set>
#include<queue>
#include<math.h>
using namespace std;
#define N (1000000000+7)
#define INF 1e16
typedef long long ll;
typedef pair<ll,ll> P;


int main(void){
    string s;
    cin>>s;
    int len = s.length();
    int ans = 10000000;
    for(int i=0;i<len-1;i++){
        if(s[i]!=s[i+1]) ans = min(ans,max(i+1,len-i-1));
    }
    if(ans == 10000000)ans = len;
    cout<<ans<<endl;
    return 0;
}