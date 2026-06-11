#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
#define co(x) cout << (x) << "\n"
#define cosp(x) cout<< (x) << " "

int main(){
    int x1,y1,x2,y2;cin>>x1>>y1>>x2>>y2;
    int dx = x2-x1, dy = y2-y1;
    cosp(x2-dy);cosp(y2+dx);cosp(x1-dy);cosp(y1+dx);printf("\n");
}