#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define pii pair<int,int>
const long long MOD=1000000007;

int main(){
    int n;
    cin>>n;
    double sum=0;
    rep(i,n){
        double x;
        string u;
        cin>>x>>u;
        if(u=="JPY") sum+=x;
        else sum+=x*380000;
    }
    cout<<fixed<<setprecision(10)<<sum<<endl;
    return 0;
}