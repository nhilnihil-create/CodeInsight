#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using P = pair<int,int>;

// O(\sqrt{n})
bool is_prime(int n){
    for(int i=2; i*i <= n; i++){
        if(n%i == 0) return false;
    }
    return n != 1; // n == 1 のときは例外
}

int main(void){
    int n;
    cin >> n;

    map<int, int> pr;
    for(int i = 1; i <= n; i++){
        for(int j = 2; j <= i; j++){
            int cur = i;
            if(is_prime(j)){
                while(cur % j == 0){
                    pr[j]++;
                    cur /= j;
                }
            }
        }
    }

    vector<int> a = {2, 4, 14, 24, 74};
    map<int, int> num;
    for(int i = 2; i <= n; i++){
        for(int k = 0; k < 5; k++){
            if(pr[i] >= a[k]) num[a[k]]++;
        }
    }

    // cout << num[2] << " " << num[4] << " " << num[14] << " " << num[24] << " " << num[74] << endl;
    int ans = ((num[2] - 2) * (num[4] - 1) * num[4]) / 2 + ((num[4] - 1) * num[14]) + ((num[2] - 1) * num[24]) + (num[74]);
    cout << ans << endl;
    return 0;
}