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
    string x,y;
    cin>>x>>y;
    int a=x.length(),b=y.length();
    if(a!=b)
        cout<<"No"<<endl;
    else{
        for(int i=0;i<a;i++){
            char temp=x[0];
            x.erase(x.begin()+0);
            x+=temp;
            if(x==y){
                cout<<"Yes"<<endl;
                return 0;
            }
        }
         cout<<"No"<<endl;
    }


    return 0;
}
