#include <iostream>
#include<bits/stdc++.h>

using namespace std;
typedef long long LL;

int main()
{
    LL N;
    string S;
    cin>>N;
    cin>>S;

    for(LL j=0; j<N/2; j++){
        char a = S[2*N - 1-j];
        S[2*N - 1- j] = S[N+j];
        S[N+j] = a;
    }

    LL counter = 0;
    for(LL i=0; i<1<<N; i++){
        string s1,s2;
        for(LL j=0; j<N; j++){
            if( (i>>j)%2 == 0){
                s1 += S[j];
            }
            else{
                s2 += S[j];
            }
        }
        LL l1 = s1.length();
        LL l2 = s2.length();





        LL dp[N+1][N+1];
        dp[0][0] = 1;
        for(LL j1 = 1; j1< N+1; j1++){
            for(LL j2 = 0; j2 <= j1; j2++){
                dp[j1][j2] = 0;
                if(j2 > 0 && j2 <= l1){
                    if(S[N + j1 - 1] == s1[j2 - 1]){
                        dp[j1][j2] += dp[j1-1][j2-1];
                    }
                }
                if(j2 < j1 && j1-j2 <= l2 ){
                    if(S[N+j1-1] == s2[j1-j2-1]){
                        dp[j1][j2] += dp[j1-1][j2];
                    }
                }

            }
        }
        counter += dp[N][l1];



    }
    cout<<counter<<endl;

    return 0;
}
