#include <iostream>
#include <math.h>
#include <vector>
#include <bitset>
using namespace std;
const long long INF = 1LL<<60;

bool IsPrime(int num){
        if (num < 2) return false;
        else if (num == 2) return true;
        else if (num % 2 == 0) return false;

        double sqrtNum = sqrt(num);

        for (int i = 3; i <= sqrtNum; i += 2){
                if (num % i == 0) return false;
        }

        return true;
}

int main(){

        int n;
        cin >> n;
        vector<int> l(n), r(n), sum(n);
        for (int i=0; i < n; ++i) {
                        cin >> l[i] >> r[i];
        }

        int MAX = 101010;
        vector<int> is_prime(MAX, 1);
        is_prime[0] = 0;
        is_prime[1] = 0;
        for (int i = 2; i < MAX; ++i) {
                if (!is_prime[i]) continue;
                for (int j = i*2; j < MAX; j += i) is_prime[j] = 0;
        }

        vector<int> a(MAX, 0);
        for (int i = 0; i < MAX; ++i){
                if (i % 2 == 0) continue;
                if (is_prime[i] && is_prime[(i+1)/2]) a[i] = 1;
        }

        vector<int> s(MAX+1, 0);
        for (int i = 0; i < MAX; i++) s[i+1] = s[i] + a[i];

        for (int i = 0; i < n; i++) {
                cout << s[r[i]+1] - s[l[i]] << endl;
        }
}