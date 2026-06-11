#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(),v.end()
#define _GLIBCXX_DEBUG

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vd = vector<double>;
using vvi = vector<vi>;
using vvll = vector<vll>;
using vvd = vector<vd>;
using vvvi = vector<vvi>;
using vvvll = vector<vvll>;
using vvvd = vector<vvd>;

const double pi=acos(-1);
const ll MOD=1e9+7;
const ll INF=(1LL<<60);

int main() {
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    vi d;
    int c=1;
    if (s[0]=='0')d.push_back(0);
    int now=s[0]-'0';
    for (int i=1;i<n;i++){
        if (now!=s[i]-'0'){
            d.push_back(c);
            c=1;
            now=s[i]-'0';
        }
        else c+=1;
    }
    d.push_back(c);
    if (s[n-1]=='0')d.push_back(0);
    int ans1=0,ans=0;
    ans1+=d[0];
    int num=d.size();
    if (k>=num/2){
        cout<<n<<endl;
        return 0;
    }
    for (int i=1;i<2*k;i+=2){
        ans1+=d[i]+d[i+1];
    }
    ans=ans1;
    for (int i=1;2*k+1+i<num;i+=2){
        ans1-=d[i-1]+d[i];
        ans1+=d[2*k+i]+d[2*k+i+1];
        ans=max(ans,ans1);
    }
    cout<<ans<<endl;



    return 0;
}