#include <bits/stdc++.h>

using namespace std;

int main(){
    long long int N,M,sum=0,ans=0;
    cin >> N >> M;
    vector<long long int> A(N);
    map<long long int,long long int> mp;
    for(int i=0;i<N;i++){
        cin >> A[i];
    }

    mp[A[0]%M]++;
    sum = A[0]%M;

    for(int i=1;i<N;i++){
        sum += A[i];
        sum %= M;
        mp[sum]++;
    }

    for(auto itr = mp.begin();itr!=mp.end();itr++){
        ans += itr->second*(itr->second-1)/2;
    }

    cout << ans + mp[0] << endl;
}