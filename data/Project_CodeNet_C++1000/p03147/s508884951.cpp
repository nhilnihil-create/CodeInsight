#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int main(void)
{
    int N;
    cin >> N;
    vector<int> h(N);
    for (int i = 0; i < N; i++)
    {
        cin >> h[i];
    }

    int totalShimaCnt = 0;
    for(int k = 1; k <= 100; k++){
        int shimaCnt = 0;
        bool streak = false;
        for(int i = 0; i < N; i++){
            if(h[i] >= k){
                if(!streak){
                    shimaCnt++;
                    streak = true;
                }
            } else {
                streak = false;
            }
        }
        totalShimaCnt += shimaCnt;
    }

    cout << totalShimaCnt << endl;
    return 0;
}
