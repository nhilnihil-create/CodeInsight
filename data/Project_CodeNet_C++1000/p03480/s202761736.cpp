#include <iostream>
#include <vector>
#include <string>
using namespace std;
struct BIT{
    vector<long long> num;
    int N;
    BIT(int n){
        N = n;
        num.resize(N + 1, 0);
    }
    long long sum(long long t){
        long long res = 0;
        while(t > 0){
            res += num[t];
            t -= t & -t;
        }
        return res;
    }
    void add(int ind, long long t){
        while(ind <= N){
            num[ind] += t;
            ind += ind & -ind;
        }
    }
};
int main(){
    string S;
    cin >> S;
    int n = S.size();
    BIT bit(n);
    for(int i = 0; i < n; i++){
        if(S[i] == '0') bit.add(i + 1, 1);
    }
    for(int i = n; i >= (n + 1) / 2; i--){
        int l = n - i;
        int r = i;
        int t = bit.sum(r) - bit.sum(l);
        if(t == r - l || t == 0){
            cout << i << endl;
            return 0;
        }
    }
    cout << n / 2 << endl;
}