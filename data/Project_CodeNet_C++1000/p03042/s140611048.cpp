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
    int a=(s[0]-'0')*10+(s[1]-'0');
    int b=(s[2]-'0')*10+(s[3]-'0');
    int ym=0,my=0;
    if(b<=12 && b>0) ym=1;
    if(a<=12 && a>0) my=1;
    if(ym && my) cout<<"AMBIGUOUS"<<endl;
    else if(ym) cout<<"YYMM"<<endl;
    else if(my) cout<<"MMYY"<<endl;
    else cout<<"NA"<<endl;
}
