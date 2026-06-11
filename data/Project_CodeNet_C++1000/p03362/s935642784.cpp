#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using P = pair<int,int>;
/* ちゃんと考えてわかって実装 */

int main(void){
    int n;
    cin >> n;
    // 全部 mod5 = k であるような素数ならok
    vector<int> primes;
    vector<bool> isP(55556);
    for(int i=0; i<=55555; i++){
        isP[i] = true;
    }
    isP[0] = false;
    isP[1] = false;

    for(int i=2; i<=55555; i++){
        if(isP[i] == true){
            for(int j=i; j<=55555; j+=i){
                isP[j] = false;
            }
            if(i % 5 == 4){
                primes.push_back(i);
            }
        }
    }

    for(int i=0; i<n; i++){
        cout << primes[i] << " ";
    }
    return 0;
}