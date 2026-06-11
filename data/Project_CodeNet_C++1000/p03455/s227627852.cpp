#include <bits/stdc++.h>
#define mem(i,a) memset(i,a,sizeof(i))
#define PI acos(-1.0)
#define DMAX 200000+5
#define MOD 20190823
#define eps 1e-8
#define mp make_pair
#define INF 1000000000+9
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
template<class T> inline void read(T &x){
    x=0; 
    T f=1;
    char ch=getchar();
    while(ch<'0' || ch>'9'){
        if(ch=='-'){
            f=-1;
        }
        ch=getchar();
    }
    while(ch<='9' && ch>='0'){
        x=x*10+(ch-'0');
        ch=getchar();
    }
    x*=f;
}
ll a,b,c;
map<ll,ll> m;
int main(){
    read(a),read(b);
    c=a*b;
    if(c%2==0){
        cout<<"Even"<<endl;
    }
    else{
        cout<<"Odd"<<endl;
    }
    return 0;
}