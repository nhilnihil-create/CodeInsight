#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define rep1(i,n) for(int i=1;i<=(int)n;i++)
#define sp(n) cout << fixed << setprecision(n)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
typedef long long ll;
using namespace std;
int main(void){
    int x1,x2,y1,y2;cin>>x1>>y1>>x2>>y2;
    int bufx=x2-x1,bufy=y2-y1;
    int x3=x2-bufy,y3=y2+bufx;
    int x4=x1-bufy,y4=y1+bufx;
    cout<<x3<<" "<<y3<<" "<<x4<<" "<<y4<<endl;
}