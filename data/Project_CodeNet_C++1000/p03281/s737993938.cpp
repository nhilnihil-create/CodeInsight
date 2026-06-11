#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
#define forin(in) for(int i=0; i<(int)in.size(); i++) cin>>in[i]
#define forout(out) for(int i=0; i<(int)out.size(); i++) cout<<out[i]<<endl
#define rep(i, n) for(int i=0; i<(n); i++)

int main(){
    int n; cin>> n;

    int cnt, ans=0;
    for(int i=1; i<=n; i=i+2){
        cnt =0;
        for(int j=1; j<=i; j++){
            if(i % j == 0) cnt++;
        }
        if(cnt == 8) ans++;
    }
    cout<< ans << endl;
}