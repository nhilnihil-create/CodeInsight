#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define forin(in, n) for(int i=0; i<n; i++) cin>>in[i]
#define forout(out) for(int i=0; i<(int)out.size(); i++) cout<<out[i]<<" "
#define rep(i, n) for(int i=0; i<(n); i++)

int main(){
    int n; cin>>n;
    int n2=n;
    int ans=0;
    while(1 == 1){
        ans += n%10;
        n/=10;
        if(n==0) break;
    }
    if(n2 % ans == 0){
        cout<< "Yes" <<endl;
    }else{
        cout<<"No" <<endl;
    }
}
