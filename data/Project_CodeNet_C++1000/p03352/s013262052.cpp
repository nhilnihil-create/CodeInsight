#include <bits/stdc++.h>
#include <string.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define FOR(i, m, n) for(int i = m; i < n; i++) 
#define mod 1000000007
#define pi 3.1415926535
typedef long long ll;

int main(){
    int X;
    cin>>X;
    int ma=0;
    FOR(i,1,X+1){
        FOR(j,2,10){
            if(pow(i,j)>X){
                break;
            }
            ma=max(ma,(int)pow(i,j));
        }
    }
    cout<<ma<<endl;
    return 0;
}