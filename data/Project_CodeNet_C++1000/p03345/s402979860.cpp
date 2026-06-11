# include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define pii pair<int,int>
typedef long long ll;
ll a,b,c,k;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>a>>b>>c>>k;
    if(k&1){
        cout<<-1*(a-b)<<endl;
    }
    else cout<<a-b<<endl;
}