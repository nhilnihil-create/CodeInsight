#include <bits/stdc++.h>

using namespace std;

int main(){
    int N,K,add=1,ans=0,now=0;
    cin >> N >> K;
    string S;
    cin >> S;
    vector<int> sum;
    bool zero;
    if(S[0]=='0'){
        zero = true;
    }else{
        zero = false;
    }

    for(int i=1;i<N;i++){
        if(zero){
            if(S[i]=='0'){
                add++;
            }else{
                sum.push_back(add);
                zero = false;
                add = 1;
            }
        }else{
            if(S[i]=='0'){
                sum.push_back(add);
                add = 1;
                zero = true;
            }else{
                add++;
            }
        }
    }

    sum.push_back(add);

    if(S[0]=='0'){
        for(int i=0;i<min((int)sum.size(),2*K);i++){
            ans += sum[i];
        }

        for(int i=1;i<min((int)sum.size(),2*K+2);i++){
            now += sum[i];
        }

        ans = max(ans,now);

        for(int i=2*K+2;i<sum.size();i++){
            if(i%2==0){
                now = now-sum[i-2*K-1]-sum[i-2*K]+sum[i];
            }else{
                now = now+sum[i];
            }
            ans = max(ans,now);
        }
        
    }else{
        for(int i=0;i<min((int)sum.size(),1+2*K);i++){
            ans += sum[i];
        }

        now = ans;

        for(int i=2*K+1;i<sum.size();i++){
            if(i%2==0){
                now = now+sum[i];
            }else{
                now = now-sum[i-2*K-1]-sum[i-2*K]+sum[i];
            }
            ans = max(ans,now);
        }
    }

    cout << ans << endl;
}