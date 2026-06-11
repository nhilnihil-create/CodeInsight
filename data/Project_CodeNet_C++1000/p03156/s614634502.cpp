#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
#define REP(i,n) for (int i=0;i<(n);i++)
#define REP1(i,a,b) for(int i=(a);i<=(b);i++)
#define em emplace_back
#define ALL(x) (x).begin(),(x).end()
#define F first
#define S second
#define mkp make_pair
#define pii pair<int,int>
#define oi ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define pll pair<ll,ll>


int main(){
    //oi;
    int n,x[3]={},a,b,y;
    cin>>n>>a>>b;
    while(n--){
        cin>>y;
        if(y<=a) x[0]++;
        else if(y>a&&y<=b) x[1]++;
        else x[2]++;
    }
    cout<<min(x[0],min(x[1],x[2]))<<"\n";
//    system("pause");
    return 0;
}