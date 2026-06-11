#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int mxn= 1e5+5;
// check for forloop
// intialize variable
// overflow
// go for easy solution
#define mod 1000000007
ll INF = 1000000000000000005LL;
#define endl '\n'
void rishabh(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}
int main() {
	rishabh();
    int n;
    cin>>n;
    string str;
    cin>>str;
    ll ans=0;
    set<char> prev;
    for(int i=1;i<n;i++){
        prev.insert(str[i-1]);
        set<char> next;
        for(int j=i;j<n;j++){
            next.insert(str[j]);
        }
        ll temp=0;
        for(auto x: prev){
            if(next.count(x))temp++;
        }
        ans=max(ans,temp);
    }
    cout<<ans;
}