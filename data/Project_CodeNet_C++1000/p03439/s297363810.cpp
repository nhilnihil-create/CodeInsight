#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr int Inf = 1000000000;
constexpr ll INF= 1e18;
constexpr ll MOD = 1000000007;
const double PI = 3.1415926535897;
typedef pair<int,int> P;

int main() {
    int N;
    cin >> N;
    int a = 0;
    int b = N;
    int mid;
    vector<int> cnt(N + 1,-1);
    cout << 0 << endl;
    string S;
    cin >> S;
    if(S == "Vacant") {
        return 0;
    }
    else if(S == "Male") {
        cnt.at(0) = 1;
        cnt.at(N) = 1;
    }
    else {
        cnt.at(0) = 2;
        cnt.at(N) = 2;
    }
    for(int i = 0;i < 20;i++) {
        mid = (a + b) / 2;
        cout << mid << endl;
        cin >> S;
        if(S == "Vacant") {
            return 0;
        }
        else if(S == "Male") {
            cnt.at(mid) = 1;
        }
        else if(S == "Female") {
            cnt.at(mid) = 2;
        }
        if((b - mid) % 2 == 1 && cnt.at(mid) == cnt.at(b)) {
            a = mid;
        }
        else if((b - mid) % 2 == 0 && cnt.at(mid) != cnt.at(b)) {
            a = mid;
        }
        else {
            b = mid;
        }
    }
}