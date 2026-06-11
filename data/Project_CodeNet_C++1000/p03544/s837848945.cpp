#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)n; i++)
#define repa(i, s, n) for(int i = s; i < (int)n; i++)
using namespace std;
using ll = long long;
typedef vector<int> vi;



int main(){
    int n;
    cin >> n;
    vector<ll> ryuka(87);
    ryuka[0] = 2;
    ryuka[1] = 1;
    repa(i, 2, 87){
        ryuka[i] = ryuka[i-1] + ryuka[i-2];
    }

    cout << ryuka[n] << endl;
    return 0;
}