#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define rep1(i,n) for(int i=1;i<=(int)n;i++)
#define rep2(i,j,n) for(int j=i;j<n;j++)
#define rep3(i,j,n) for(int j=i;j<=n;j++)
#define rrep(i,n) for(int i=n-1;i>=0;i--)
#define sp(n) cout << fixed << setprecision(n)
typedef long long ll;
using namespace std;
int main(void){
    int d;cin>>d;
    switch(d){
        case 22:
            cout<<"Christmas Eve Eve Eve"<<endl;
            break;
        case 23:
            cout<<"Christmas Eve Eve"<<endl;
            break;
        case 24:
            cout<<"Christmas Eve"<<endl;
            break;
        default:
            cout<<"Christmas"<<endl;
            break;
    }
}
