# include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define pii pair<int,int>
typedef long long ll;
ll n,m;
string s,t;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>n>>m;
    cin>>s>>t;
    int fpb=__gcd(n,m);
    int x=n/fpb;
    int y=m/fpb;
    for(int i=0,j=0;i<n && j<m;i+=x,j+=y){
        if(s[i]!=t[j]){
            cout<<-1<<endl;
            return 0;
        }
    }
    cout<<(n*m)/fpb<<endl;
}