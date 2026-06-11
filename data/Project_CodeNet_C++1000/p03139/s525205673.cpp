#include <bits/stdc++.h>
#include <string.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define FOR(i, m, n) for(int i = m; i < n; i++) 
#define mod 1000000007
#define pi 3.1415926535
typedef long long ll;
int main(){
    int N,A,B;
    cin>>N>>A>>B;
    int ma=min(A,B);
    int mi;
    if(N-A-B>0){
        mi=0;
    }else{
        mi=A+B-N;
    }
    cout<<ma<<" "<<mi<<endl;
    return 0;
}