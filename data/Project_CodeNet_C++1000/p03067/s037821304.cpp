#include <bits/stdc++.h>
#include <string.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define FOR(i, m, n) for(int i = m; i < n; i++) 
#define mod 1000000007
#define pi 3.1415926535
typedef long long ll;

int main(){
    int A,B,C;
    cin>>A>>B>>C;
    int ma=max({A,B,C});
    int mi=min({A,B,C});
    if((ma==B&&mi==A)||(mi==B&&ma==A)){
        cout<<"Yes"<<endl;
    }else{
        cout<<"No"<<endl;
    }
    return 0;
}