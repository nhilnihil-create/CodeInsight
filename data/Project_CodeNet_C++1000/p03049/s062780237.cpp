#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll ZERO = 0;
const ll INF = 9223372036854775807;
const ll MOD = 1000000007;
const double PI = 3.1415926535897;
typedef pair<ll,ll> P;

int main() {
    int N;
    cin >> N;
    vector<string> vec(N);
    for(int i = 0;i < N;i++) {
        cin >> vec.at(i);
    }
    int ret = 0;
    for(int i = 0;i < N;i++) {
        for(int j = 0;j < vec[i].size() - 1;j++) {
            if(vec[i].at(j) == 'A' && vec[i].at(j + 1) == 'B') {
                ret++;
            }
        }
    }
    int A = 0;
    int B = 0;
    int C = 0;
    for(int i = 0;i < N;i++) {
        if(vec[i].at(0) == 'B' && vec[i].at(vec[i].size() - 1) == 'A') {
            A++;
        }
        else if(vec[i].at(0) != 'B' && vec[i].at(vec[i].size() - 1) == 'A') {
            B++;
        }
        else if(vec[i].at(0) == 'B' && vec[i].at(vec[i].size() - 1) != 'A') {
            C++;
        }
    }
    if(A == 0) {
        ret += min(B,C);
    }
    else {
        if(B + C > 0) {
            ret += A + min(B,C);
        }
        else {
            ret += A - 1;
        }
    }
    cout << ret << endl;
}