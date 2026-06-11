#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=int(a);i<int(b);++i)
#define SIZE 200005
#define INF 1000000005LL
#define MOD 1000000007
using namespace std;
typedef long long int ll;
typedef pair <int,int> P;
int main(){
    ll k,a,b;
    cin >> k >> a >> b;
    if(a>=b-2||(k-a+1)/2<1){
        cout<<1+k<<endl;
    }else{
        ll cnt = (k-a+1)/2;
        ll add = (k-a+1)%2;
        cout<< a+cnt*(b-a)+add<<endl;
    }
    


    return 0;
}