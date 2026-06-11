#include <bits/stdc++.h>
#include <vector>
#include <queue>
using namespace std;

int main(){
    int N;
    cin >> N;
    long long a[N];
    for(int i=0; i<N; i++){
        cin >> a[i];
    }

    long long ans = 0;
    for(int i=0; i<N; i++){
        int r = 0;

        while(r == 0){
            r = a[i] % 2;
            if(r==0){
                ans += 1;
                a[i] = a[i]/2;
            }
        }
    }

    cout << ans << endl;
    return 0;

}