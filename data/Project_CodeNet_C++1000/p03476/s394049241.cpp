#include <iostream>
#include <vector>
using namespace std;
const int MAX = 100010;

int main(){
    int q;
    cin >> q;
    vector<int> l(q), r(q);
    for(int i = 0; i < q; i++) cin >> l[i] >> r[i];

    vector<bool> is_prime(MAX, true);
    is_prime[0] = false;
    is_prime[1] = false;
    for(int i = 2; i*i < MAX; i++){
        if(is_prime[i]){
            for(int j = 2; i*j < MAX; j++) is_prime[i*j] = false;
        }
    }

    vector<int> memo(MAX, 0);
    for(int i = 1; i < MAX; i++){
        memo[i] = memo[i-1];
        if(i % 2){
            if(is_prime[i] && is_prime[(i+1)/2]){
                memo[i]++;
            }
        }
    }

    for(int i = 0; i < q; i++){
        cout << memo[r[i]]-memo[l[i]-1] << endl;
    }
    return 0;
}