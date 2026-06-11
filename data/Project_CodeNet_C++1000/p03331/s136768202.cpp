#include <bits/stdc++.h>
#include <string.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define FOR(i, m, n) for(int i = m; i < n; i++) 
#define mod 1000000007
#define pi 3.1415926535
typedef long long ll;

int main(){
    string N;
    cin>>N;
    int n=stoi(N);
    int size=N.size();
    int sum=0;
    rep(i,size){
        sum+=N[i]-48;
    }
    if(n==(int)pow(10,size-1)){
        cout<<10<<endl;
    }else{
        cout<<sum<<endl;
    }
    return 0;
}