#include <bits/stdc++.h>
#include <string>
#include <vector>
#define rep(i,n) for (int i = 0;i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;




int main(){
    int n;
    cin >> n;
    vector<string> s(n);
    vector<int> cnt(4);
    rep(i,n) {
        string s;
        cin >> s;
        rep(j,s.size()-1){  
            if(s[j]=='A'&&s[j+1]=='B') cnt[0]++;
        }
        if(s[0]=='B'){
            if(s[s.size()-1]=='A') cnt[1]++;
            else cnt[3]++;
        }else if(s[s.size()-1]=='A') cnt[2]++;
    }
    //rep(i,4) cout << cnt[i] << endl;

    if(cnt[1] >= 1){
        cnt[0] += cnt[1]-1;
        cnt[1] = 1;
    }
    
    //if(cnt[2]+cnt[3]>0) cnt[0] += cnt[1]+min(cnt[2],cnt[3]);
    cnt[0] += min(cnt[1],cnt[3]) + min(max(cnt[1],cnt[3]),cnt[2]);
    cout << cnt[0] << endl;

    // rep(i,2)rep(j,10000)rep(k,10000){
    //     int a,b;
    //     a = 0;
    //     if(j+k>0) a = i+min(k,j);
    //     b = min(i,k)+min(max(i,k),j);
    //     if(a != b) cout << i << " "<< j << " "<< k << endl;


    // }
}
