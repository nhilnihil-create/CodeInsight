#include <bits/stdc++.h>
using namespace std;

const int N = pow(10,5);

vector<int> is_prime(N+2, 1);

void sieve() {
  is_prime[0] = 0;
  is_prime[1] = 0;
  for (int i=2; pow(i,2)<=N+1; i++) {
    if (is_prime[i]==1) for(int j=2; i*j<=N+1; j++) is_prime[i*j] = 0;
  }
}

int main(){
    // エラストテネスの篩
    sieve();

    // like 2017
    vector<int> is_like_2017(N+1, 0);
    for (int i = 0; i <= N; i++)
    {
        if (i%2 == 0){
            continue;
        } 
        if (is_prime[i] == 1 && is_prime[(i+1)/2]==1)
        {
            is_like_2017[i] = 1;
        }
    }

    // 累積和
    vector<int> sums_like_2017(N+1, 0);
    int sum_like_2017 = 0;
    for (int i = 0; i <= N; i++)
    {
        if (is_like_2017[i] == 1)
        {
            sum_like_2017++;
        }
        sums_like_2017[i] = sum_like_2017;
    }
    
    // query
    int Q;
    cin >> Q;
    int l, r;
    for (int i = 0; i < Q; i++)
    {
        cin >> l >> r;
        cout << sums_like_2017[r] - sums_like_2017[l-1] << endl;
    }

    return 0;
}
