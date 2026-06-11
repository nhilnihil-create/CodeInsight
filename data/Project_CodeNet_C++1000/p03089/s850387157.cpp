#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i=0;i<(n);++i)
#define repi(i,a,b) for(int i=int(a);i<int(b);++i)
#define all(x) (x).begin(), (x).end()
#define PI 3.14159265358979323846264338327950L
using namespace std;
typedef long long ll;
typedef long double ld;
int main() {
    int n;
    cin>>n;
    vector<int> b(n),a(n);
    rep(i,n) cin>>b[i];
    rep(i,n){
        int num=-1;
        for(int j=b.size()-1;j>=0;j--){
            if(b[j]==j+1){
                num=j;
                break;
            }
        }
        if(num==-1){
            cout<<-1;
            return 0;
            }
        a[i]=num+1;
        b.erase(b.begin()+num);
    }
    rep(i,n) cout<<a[n-1-i]<<endl;
}