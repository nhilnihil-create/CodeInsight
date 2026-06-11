#include <bits/stdc++.h>
using namespace std;

int main(){
    long long int n, k;
    cin >> n >> k;

    vector<long long int> a(n);
    for(int i=0; i<n; i++){
        cin >> a[i];
    }

    long long int ans = 0;
    for(int d=39; d>=-1; d--){
        if(d >= 0 && !(k & (1LL<<d))) continue;

        // if (d-th bit of k) == 1
        long long int test = 0;
        for(int i=39; i>=0; i--){
            int count0 = 0, count1 = 0;

            for(int j=0; j<n; j++){
                if(a[j] & (1LL<<i)) count1 += 1;
                else count0 += 1;
            }
            //cout << count0 << " " << count1 << endl;

            if(i > d){
                if(k & (1LL<<i)) test += (1LL<<i) * count0;
                else test += (1LL<<i) * count1;
            }
            if(i == d){
                test += (1LL<<d) * count1;
            }
            if(i < d){
                test += (1LL<<i) * max(count0, count1);
            }
        }
        ans = max(ans, test);
    }
    cout << ans << endl;
    return 0;
}