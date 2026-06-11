#include <bits/stdc++.h>
using namespace std;
#define int long long

vector<int> prime(100005, 1);

void prime_number(){
    for (int i=2; i * i < 100005; i++){
        if(prime[i]){
            for (int j = i * 2; j < 100005; j += i){
                prime[j] = 0;
            }
        }
    }
}

signed main(void){
    int q; cin >> q;
    prime_number();
    // 
    
    vector<int> num_list(100004, 0);
    for (int i=1; i<100004; i++){
        if (i%2 == 1 && prime[i] && prime[(i + 1) / 2]) num_list[i] = 1;
        else num_list[i] = 0;
    }
    num_list[1] = 0;
    // for (int i=1; i< 54; i++) if(num_list[i]) cout << i << " ";
    // cout << endl;
    vector<int> s(100005, 0);
    for (int i=1; i<100005; i++){
        s[i] = s[i-1] + num_list[i];
    }
    for (int i=0;i <q; i++){
        int l, r;
        cin >> l >> r;
        cout << s[r] - s[l-1] << endl;
        // if (l == r){
        //     // if (num_list[l]) cout << 1 << endl;
        //     cout << s[r] - s[l-1] << endl;
        // }else{
        //     cout << s[r] - s[l-1] << endl;
        // }
        
    }
}
