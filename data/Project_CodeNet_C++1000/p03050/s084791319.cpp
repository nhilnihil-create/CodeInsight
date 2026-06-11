#include <bits/stdc++.h>
using namespace std;

int main(){
    long long int n;
    cin >> n;

    vector<long long int> div;
    for (long long int i=1; i*i<=n; i++){
        if (n % i == 0){
            div.push_back(i);

            long long int j = n / i;// counterpart
            if (j != i) div.push_back(j);
        }
    }
    sort(div.begin(), div.end());

    long long int ans = 0;
    for(auto d :div){
        if(d < n/d - 1) ans += n/d - 1;
    }
    cout << ans << endl;
    return 0;
}