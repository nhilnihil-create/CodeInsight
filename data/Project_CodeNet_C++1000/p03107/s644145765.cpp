
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
const ll INF = 1LL << 60;

int main(){
    string s;
    cin >> s;
    int count0=0;
    int count1=0;
    int n=s.size();
    for(int i=0; i<n; i++){
        if(s[i]=='0') count0 ++;
        else count1 ++;
    }
    int ans = 2*min(count0,count1);
    cout << ans << endl;


}