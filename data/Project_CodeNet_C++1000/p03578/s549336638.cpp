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
    vector<int>D(N);
    map<int,int>s;
    rep(i,N){
        cin>>D[i];
        s[D[i]]++;
    }
    int M;
    cin>>M;
    vector<int>T(M);
    rep(i,M){
        cin>>T[i];
    }
    int count=0;
    rep(i,M){
        if(s[T[i]]>0){
            count++;
            s[T[i]]--;
        }
    }
    if(count==M){
        cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;
    }

    return 0;
}