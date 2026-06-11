#include <bits/stdc++.h>
#define FOR(i, begin, end) for(ll i=(begin);i<=(end);i++)
#define REP(i, n) FOR(i,1,n)
#define IFOR(i, begin, end) for(ll i=(end);i>=(begin);i--)
#define IREP(i, n) IFOR(i,1,n)
#define SORT(a) sort(a.begin(), a.end())
#define REVERSE(a) reverse(a.begin(), a.end())

#define ll long long
using namespace std;

int main()
{
	stringstream ss;
    // 入力
    ll N;
    cin>>N;
    int k=-1;

    for(int i=1;i*(i-1)/2<=N;i++){
        // cout<<i*(i-1)/2<<endl;
        if(i*(i-1)/2==N) {
            k=i;
            break;
        }
    }
    if(k==-1) {
        cout<<"No"<<endl;
        return 0;
    }
    cout<<"Yes"<<endl;
    cout<<k<<endl;
    
    ll id=1;
    ll S[k+1][k+1];
    FOR(i,1,k){
        FOR(j,i+1,k){
            S[i][j]=id;
            S[j][i]=id;
            id++;
        }
    }

    FOR(i,1,k){
        cout<<k-1<<" ";
        FOR(j,1,i-1){
            cout<<S[i][j]<<" ";
        }
        FOR(j,i+1,k-1){
            cout<<S[i][j]<<" ";
        }
        if(i<k) cout<<S[i][k]<<endl;
    }

    return 0;
}