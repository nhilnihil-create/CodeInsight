#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cmath>
#include<cstdio>
#include<queue>
#include<deque>
#include<map>
#include<stack>
#include<set>
#include<utility>
using namespace std;
typedef pair<int,int> ii;
typedef long long ll;
typedef pair<int,int> P;
typedef unsigned long long int ull;
const int MOD=1e9+7;
int dy[]={1,0,-1,0};
int dx[]={0,1,0,-1};
const int MAXN=100000;
const int MAXE=100000;
const int MAXV=10000;
const int INF=1e9;

int main(){
    string s;cin>>s;
    int n=(int)s.size();
    vector<int> cnt(n,0);
    int c=0;
    for(int i=n-1;i>=0;i--){
        if(s[i]=='C'){
            if(i>0&&s[i-1]=='B'){
                c++;
                i--;
            }else c=0;
        }else if(s[i]=='A') cnt[i]=c;
        else c=0;
    }
    ll ans=0;
    for(int i=0;i<n;i++){
        ans+=cnt[i];
    }
    cout<<ans<<endl;
    return 0;
}