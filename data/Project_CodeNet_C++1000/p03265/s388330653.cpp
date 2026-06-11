#include<bits/stdc++.h>
using namespace std;
///Welcome to Nasif's Code
#define bug printf("bug\n");
#define bug2(var) cout<<#var<<" "<<var<<endl;
#define co(q) cout<<q<<endl;
#define all(q) (q).begin(),(q).end()
typedef long long int ll;
typedef unsigned long long int ull;
const int MOD = (int)1e9+7;
const int MAX = 1e6;
#define pi acos(-1)
#define inf 1000000000000000LL
#define FastRead    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int main()
{
    FastRead
    //freopen("output.txt", "w", stdout);
    int x1,y1,x2,y2,d;
    cin>>x1>>y1>>x2>>y2;
    int dx=x2-x1, dy=y2-y1;
    int x3=x2-dy, y3=y2+dx;
    int x4=x3-dx, y4=y3-dy;
    cout << x3 << " " << y3 << " " << x4 << " " << y4 << endl;
    


    return 0;
}
