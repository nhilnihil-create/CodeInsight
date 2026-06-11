#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
#define forin(in) for(int i=0; i<(int)in.size(); i++) cin>>in[i]
#define forout(out) for(int i=0; i<(int)out.size(); i++) cout<<out[i]<<endl
#define rep(i, n) for(int i=0; i<(n); i++)

int main(){
    const char acgt[]={'A', 'C', 'G', 'T'};
    string s; cin>> s;
    int ans = 0;
    int cnt = 0;
    int judge = 0;
    for(int i=0; i<s.size(); i++){
        rep(j, 4){
            judge++;
            if(acgt[j] == s[i]){
                judge = 5;
                cnt++;
                ans = max(ans, cnt);
            }
        }
        if(judge == 4) cnt=0;
        judge = 0;
    }
    cout<< ans << endl;
}