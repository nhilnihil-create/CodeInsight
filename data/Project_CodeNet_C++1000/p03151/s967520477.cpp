#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int N;
    cin>>N;
    vector<ll> A(N),B(N);
    for(int i=0; i<N; i++) cin>>A[i];
    for(int i=0; i<N; i++) cin>>B[i];

    ll asum = 0;
    ll bsum = 0;
    for(int i=0; i<N; i++) asum += A[i];
    for(int i=0; i<N; i++) bsum += B[i];

    if(asum < bsum){
        cout<<-1<<endl;
    }

    else{
        ll ans = 0;
        ll sum = 0;
        vector<ll> dif;
        for(int i=0; i<N; i++){
            if(B[i] > A[i]){
                sum += abs(A[i] - B[i]);
                ans++;
            }
            else if(B[i] < A[i]) dif.push_back(A[i] - B[i]);
        }

        if(ans == 0){
            cout<<ans<<endl;
            return 0;
        }

        sort(dif.begin(),dif.end(),greater<ll>());

        for(auto a : dif){
            if(sum > a){
                ans++;
                sum -= a;
            }else{
                ans++;
                break;
            }
        }

        cout<<ans<<endl;
    }

    return 0;
}