#include<bits/stdc++.h>
using namespace std;
#define rep(i,n); for(int i = 0;i < (int)(n);i++)
#define all(x) (x).begin(),(x).end()
typedef long long ll;

int main(){
    int n;
    cin >> n;
    vector<char>s(n);
    rep(i,n)cin >> s[i];
    int ans = 0;
    for(int i = 0;i < n-1;i++){
        int sum = 0;
        vector<bool>al1(26),al2(26);
        rep(j,n){
            al1[j]=false; al2[j] = false;
        }
        for(int j = 0;j<n;j++){
            if(j<=i)al1[s[j]-'a']=true;
            else al2[s[j]-'a']=true;
        }
        rep(j,26){
            if(al1[j]&&al2[j])sum++;
        }
        ans = max(ans,sum);
    }
    cout << ans << endl;
    return 0;
}