#include <bits/stdc++.h>

using namespace std;

int is_prime(int n){
    if(n < 2){
        return 0;
    }else if(n == 2){
        return 1;
    }
    if(n%2 == 0){
        return 0;
    }

    for(int i = 3; i<=sqrt(n); i+=2){
        if(n%i == 0){
            return 0;
        }
    }
    return 1;
}


const int N =100010;
vector<int> p(N);
void solve() {
    int Q;
    cin >> Q;
    for (int i = 1; i < N; i++)
    {
        if (i % 2 == 0)
        {
            p[i] = p[i-1];
            continue;
        }
        
        if (is_prime(i) && is_prime((i + 1) / 2))
        {
            p[i] = p[i-1] + 1;
        }
        else
        {
            p[i] = p[i-1];
        }
    }

    for (int i = 0; i < Q; i++)
    {
        int l, r;
        cin >> l >>  r;
        cout << p[r] - p[l-1] << endl;
    }
    
}

int main() {
    solve();
    return 0;
}