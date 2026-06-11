#include <bits/stdc++.h>

int main(){
    using namespace std;
    int N; cin >> N;
    vector<int> v(N);
    for (int i = 0; i < N; i++) cin >> v[i];

    int r = 0;
    long long cnt = 0, sum = 0;
    for (int i = 0; i < N; i++)
    {
        while (r<N && ( (sum^v[r]) == sum+v[r]))
        {
            sum += v[r];
            r++;
        }
        cnt += r - i;
        if(i==r) r++;
        else sum -= v[i];
    }
    cout << cnt << endl;
}