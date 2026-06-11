#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define reps(i,s,n) for (int i = (s); i <= (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {

    int N;
    cin >> N;
    int a[N];
    for(int i = 0; i < N; i++){
    cin >> a[i];
    }


    int ans = 0;
    for(int i = 0; i < N; i++){
        int num = a[i];

        while(a[i] % 2 == 0 ){
            a[i] /= 2;
            ans++;
        }
    }

    cout << ans << endl;
    // int ans = 0;
    // while(1){
    //     vector<int> even_num;
    //     int Max = -1;

    //     for(int i = 0; i < N; i++){
    //         if(a[i] % 2 == 0){
    //             even_num.push_back(a[i]);
    //             Max = max(Max, a[i]);
    //         }
    //     }

    //     if(even_num.size() == 0)
    //         break;
        
    //     for(int i = 0; i < N; i++){
    //         if(a[i] == Max)
    //             a[i] /= 2;
    //         else
    //             a[i] *= 3;
    //     ans++;
    // }
    // cout << ans << endl;

    return 0;
}