#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)

int main(void){
    string s;
    cin>>s;
    int n = s.size();
    map<char,int> cnt;
    rep(i,n){
        cnt[s[i]]++;
    }
    int a[] = {cnt['a'],cnt['b'],cnt['c']};
    sort(a,a+3);
    cout<<((a[2] - a[0] <= 1) ? "YES" : "NO")<<endl;
    return 0;
}
