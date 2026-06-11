#include <bits/stdc++.h>
#include <string>
#include <vector>
#include <algorithm>
#define rep(i,n) for (int i = 0;i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
int INF = 1e9;

bool query(int &l,int &r,char &lch){
    int mid = (l+r)/2;
    if(r-l==2) cout << l+1 << "\n" << flush;
    else cout << mid << "\n" << flush;
    string s; cin >> s;
    if(s[0] == 'V') return true;
    else if(s[0]==lch){
        if((mid-l)%2==0) l = mid;
        else r = mid;
    }else{
        if((mid-l)%2==1) {
            l = mid;
            lch = s[0];
        }else r = mid;
    }
    return false;
}

int main(){
    int n;cin >> n;
    bool flag = false;
    cout << 0 << "\n" << flush;
    string s;cin >> s;
    if(s[0]=='V') return 0;
    int l = 0;
    int r = n;
    while(!flag){
        flag = query(l,r,s[0]);
    }
    return 0;
    
}