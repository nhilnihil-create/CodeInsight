#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define forin(in, n) for(int i=0; i<n; i++) cin>>in[i]
#define forout(out) for(int i=0; i<(int)out.size(); i++) cout<<out[i]<<" "
#define rep(i, n) for(int i=0; i<(n); i++)

vector<int> digit(int n){
    vector<int> ans;
    while(1 == 1){
        ans.push_back(n % 10);
        n/=10;
        if(n==0) break;
    }
    return ans;
}


int main(){
    int a, b; cin>> a >> b;
    int cnt=0;
    vector<int> keta;
    for(int i=a; i<=b; i++){
        keta=digit(i);
        if(keta[0] == keta[4] && keta[1] == keta[3]) cnt++;
    }
    cout << cnt <<endl;
}