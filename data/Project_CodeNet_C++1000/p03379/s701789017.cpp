#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;


int main(void)
{
    int N;
    cin >> N;
    vector<int> X(N);
    vector<int> sorted(N);
    for (int i = 0; i < N; i++)
    {
        cin >> X[i];
        
        sorted[i] = X[i];
    }


    sort(sorted.begin(), sorted.end());

    int mid = sorted[N/2];
    int pre = sorted[N/2 - 1];

    for(int i = 0; i < N; i++){
        int x = X[i];
        int pos = lower_bound(sorted.begin(), sorted.end(), x) - sorted.begin();
        if(pos < N/2){
            cout << mid << endl;
        } else {
            cout << pre << endl;
        }
    }
    
    return 0;
}
