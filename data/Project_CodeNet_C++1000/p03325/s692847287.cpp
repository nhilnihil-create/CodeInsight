#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define fr first
#define sc second
const int mod = 1e9+7;
const int N = 1e6+6;
ll a[N];
int lg2(int x){
    int ret = 0;
    while(x%2==0){
        x/=2;
        ret++;
    }
    return ret;
}
int main(){
    int n;
    cin>>n;
    int ans = 0;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        ans+=lg2(x);
    }
    cout<<ans<<endl;
}
