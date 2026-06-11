#include<bits/stdc++.h>

using namespace std;


double dp[305][305][305];


// dp[one][two][three]
// 

int N=302;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    vector<int> cnt(3+1);
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        cnt[x]++;
    }

    // dp[0][0][0]=1;
    for(int three=0;three<N;three++){
        for(int two=0;two<N;two++){
            for(int one=0;one<N;one++){
    // for(int three=0;three<=cnt[3];three++){
    //     for(int two=0;two<=cnt[2];two++){
    //         for(int one=0;one<=cnt[1];one++){
                if(one+two+three == 0){
                    continue;
                }
                if(one+two+three>n){
                    continue;
                }
                dp[one][two][three]=1;
                if(one!=0){
                    dp[one][two][three]+=(dp[one-1][two][three])*((double)one/n);
                }
                if(two!=0){
                    dp[one][two][three]+=(dp[one+1][two-1][three]*((double)two/n));
                }
                if(three!=0){
                    dp[one][two][three]+=(dp[one][two+1][three-1]*((double)three/n));
                }

                int zeroes=(n-one-two-three);
                dp[one][two][three]/=(1.0 - 1.0*zeroes/(double)(n));
            }
        }
    }
    cout<<setprecision(9)<<fixed;
    cout<<dp[cnt[1]][cnt[2]][cnt[3]]<<endl;
}