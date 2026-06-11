//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pp pair<int,int>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define ld long double
#define al(a) (a).begin(),(a).end()
#define mk make_pair
#define check cout<<"?"<<endl;

ll MOD=1000000007;
ll mod=998244353;
int inf=1000001000;
ll INF=1e18+5;

int main(){
    string s; cin>>s;
    int n=s.size();
    if(s.back()=='1' || s[0]=='0'){
        printf("-1\n");
        return 0;
    }
    rep(i,n-1){
        if(s[i]!=s[n-2-i]){
            printf("-1\n");
            return 0;
        }
    }
    int cnt=1;
    for(int i=2;i<=n-1;i++){
        if(s[i-1]=='1'){
            rep(j,cnt) printf("%d %d\n",i-j-1,i);
            cnt=1;
        }
        else{
            cnt++;
        }
    }
    printf("%d %d\n",n-1,n);
}
