#include <bits/stdc++.h>

using namespace std;

int main(){
    long long int N,ren=1,ans=0;
    cin >> N;
    vector<long long int> A(N),sum(N+1);
    sum[0] = 0;
    for(int i=0;i<N;i++){
        cin >> A[i];
        sum[i+1] = sum[i] + A[i];
    }

    sort(sum.begin(),sum.end());

    for(int i=1;i<=N;i++){
        if(sum[i]==sum[i-1]){
            ren++;
        }else{
            ans += ren*(ren-1)/2;
            ren = 1;
        }
    }

    ans += ren*(ren-1)/2;

    cout << ans << endl;
}