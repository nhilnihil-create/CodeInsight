#include <iostream>
#include <algorithm>

using namespace std;

bool used[100000];

int main(){
    int N;
    long L[100000], R[100000];
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> L[i] >> R[i];
    }
    sort(L, L+N, greater<int>());
    sort(R, R+N);
    long ans = 0;
    long tmp = 0;
    for(int i = 0; i < N; i++){
        int cur = i/2;
        if(i%2 == 0) tmp += 2*L[cur];
        else tmp -= 2*R[cur];
        ans = max(tmp, ans);
    }
    tmp = 0;
    for(int i = 0; i < N; i++){
        int cur = i/2;
        if(i%2 == 0) tmp -= 2*R[cur];
        else tmp += 2*L[cur];
        ans = max(tmp, ans);
        cur++;
    }
    cout << ans << endl;
}