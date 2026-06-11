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
    vector<int>P(N);
    int count_1=0,count_2=0, count_3=0;
    rep(i,N){
        cin>>P[i];
        if(P[i]<=A){
            count_1++;
        }else if(P[i]>=A+1&&P[i]<=B){
            count_2++;
        }else if(P[i]>=B+1){
            count_3++;
        }
    }
    cout<<min({count_1,count_2,count_3})<<endl;
    return 0;
}