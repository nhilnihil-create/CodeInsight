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
    int n,m,x,y,mx=-INT_MAX,my=INT_MAX;
    cin>>n>>m>>x>>y;
    vector<int>a,b;
    for(int i=0;i<n;i++){
        int c;
        cin>>c;
        a.push_back(c);
        mx=max(mx,c);
    }
    for(int i=0;i<m;i++){
        int c;
        cin>>c;
        b.push_back(c);
        my=min(my,c);
    }
    for(int i=x+1;i<=y;i++){
      if(i>mx && i<=my)
      {
          cout<<"No War"<<endl;
          return 0;
      }

    }



   cout<<"War"<<endl;
    return 0;
}
