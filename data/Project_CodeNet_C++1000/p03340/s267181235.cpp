#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr int Inf = 1000000000;
constexpr ll INF= 1e18;
constexpr ll MOD = 1000000007;
const double PI = 3.1415926535897;

int main() {
    int N;
    cin >> N;
    vector<int> vec(N);
    for(int i = 0;i < N;i++) {
        cin >> vec.at(i);
    }
    ll ret = 0;
    int right = 0;
    ll Sum = 0;
    ll Xor = 0;
    for(int left = 0;left < N;left++) {
        while(right < N && Sum == Xor) {
            if(Sum + vec.at(right) != (Xor ^ vec.at(right))) {
                break;
            }
            else {
                Sum += vec.at(right);
                Xor = (Xor ^ vec.at(right));
            }
            right++;
        }
        ret += (right - left);
        Sum -= vec.at(left);
        Xor = (Xor ^ vec.at(left));
        if(right == left) {
            right++;
        }
    }
    cout << ret << endl;
}