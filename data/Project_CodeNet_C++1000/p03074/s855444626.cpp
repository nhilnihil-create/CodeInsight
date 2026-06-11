#define _GLIBCXX_DEBUG
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
    lli k,n;
    string s;
    cin>>n>>k>>s;
    vi st;
    lli res=0;
    lli now=0;
    lli ans=0;
    char prev='1';
    rep(i,n){
        if(prev==s[i]){
                now+=1;
        }
        else{
            st.push_back(now);
            prev=s[i];
            now=1;
        }
        if(i==n-1){
            st.push_back(now);
        }
    }
    if(st.size()%2==0) st.push_back(0);
    lli add=2*k+1;
    vi sum;
    sum.push_back(0);
    rep(i,st.size()){
        sum.push_back(sum.at(sum.size()-1)+st.at(i));
    }
    for(int i=0;i<sum.size();i+=2){
        int left=i;
        int right=min(i+add,(lli)sum.size()-1);
        res=sum[right]-sum[left];
        ans=max(res,ans);
    }
    out(ans);
    
}