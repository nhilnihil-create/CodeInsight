#include <bits/stdc++.h>
#define rep(i, z, n) for(int i = z; i < n; i++)
#define all(v) v.begin(), v.end()
typedef long long ll;
//const int INF = 1<<29;
//const int MODINF = 1000000007;
using namespace std;

bool prime_number(int x){
    if (x < 2) return false;
    else if (x == 2) return true;
    else if (x % 2 == 0) return false;
    
    double sqrtN = sqrt(x);
    for (int i = 3; i <= sqrtN; i += 2){
        if (x % i == 0) return false;
    }
    return true;
}

int main(){
    int N;
    cin >> N;
    int count = 0;
    int i = 1;
    while(count < N){
        if (prime_number(i) && (i % 5 == 2)){
            cout << i << " ";
            count++;
        }
        i++;
    }
    cout << endl;
}