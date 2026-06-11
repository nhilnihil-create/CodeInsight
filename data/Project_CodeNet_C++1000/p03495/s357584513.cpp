#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N,K;
    cin >> N >> K;
    vector<int> A_cnt(N);

    int count=0;

    for(int i=0; i<N; i++){
        int a; cin >> a;

        if(A_cnt.at(a-1) == 0){
            count++;
        }
        A_cnt.at(a-1)++;
    }

    sort(A_cnt.rbegin(),A_cnt.rend());

    int ans = 0;

    for(int i=K; i<count; i++){
        ans += A_cnt.at(i);
    }

    cout << ans << endl;
}