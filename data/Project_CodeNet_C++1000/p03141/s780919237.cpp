#include <bits/stdc++.h>

using namespace std;

int main(){
    long long int N,a=0,b=0,ans=0;
    cin >> N;
    vector<long long int> sum(N);
    for(int i=0;i<N;i++){
        long long int a,b;
        cin >> a >> b;
        ans -= b;
        sum[i] = a+b;
    }

    sort(sum.begin(),sum.end());

    for(int i=N-1;0<=i;i-=2){
        ans +=sum[i];
    }

    cout << ans << endl;
}