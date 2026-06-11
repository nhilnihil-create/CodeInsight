#include <bits/stdc++.h>
using namespace std;
int main() {
    int N,K;
    cin >> N >> K;

    vector<int> I(N);

    for(int i=0;i<N;i++){
        int a;
        cin >> a;

        I.at(a-1)++;
    }

    int ans=0;

    sort(I.begin(),I.end());

    for(int i=0;i<N-K;i++){
        ans += I.at(i);
    }

    cout << ans <<endl;
    
}