
#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef unsigned long long int ulli;
#define vec(s) vector<s>;
#define vvec(s) vector<vector<s>> ;
typedef vector<lli> vi;
typedef vector<vi> vvi;
typedef pair<lli,lli> pii;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define YN(x) cout<<(bool x?"Yes":"No")<<endl;
#define out(s) cout<<s<<endl;
#define pb(s) push_back(s);
#define sp " ";
#define INF 10000000000
#define all(s) s.begin(),s.end()
void vout(vector<int> v){
    for(int i=0;i<v.size();i++)
    cout<<v.at(i)<<endl;
}
int main(){
    lli n,a=0,b=0,ans=0,sa=0;
    cin>>n;
    rep(i,n){
        string s;
        char rep='X';
        cin>>s;
        if(s[0]=='B'&&s[s.size()-1]=='A') sa++;
        else if(s[0]=='B') b++;
        else if(s[s.size()-1]=='A') a++;
        rep(j,s.size()){
            if(rep=='A' && s[j]=='B') ans++;
            rep=s[j];
        }
    }
    if(sa==0){
        ans+=min(a,b);
    }
    else{
        if(a+b!=0){
            ans+=sa+min(a,b);
        }
        else{
            ans+=sa-1;
        }
    }
    out(ans);
}