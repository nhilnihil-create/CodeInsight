#include <bits/stdc++.h>
#include <string.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define FOR(i, m, n) for(int i = m; i < n; i++) 
#define mod 1000000007
#define pi 3.1415926535
typedef long long ll;


int main(){
    int N;
    cin>>N;
    vector<int>a(N);
    int sum=0;
    rep(i,N){
        cin>>a[i];
        sum+=a[i];
    }
    double mi=100;
    int ans;
    double avg=(double)sum/N;
    rep(i,N){
        if(fabs((double)a[i]-avg)<mi){
            mi=fabs((double)a[i]-avg);
            ans=i;
        }
    }
    cout<<ans<<endl;
    return 0;
}