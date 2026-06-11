#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr int Inf = 1000000001;
constexpr ll INF= 1e18;
constexpr ll MOD = 998244353;
const double PI = 3.1415926535897;
typedef pair<int,int> P;

int main() {
    int N;
    cin >> N;
    vector<int> two;
    vector<int> three;
    vector<int> six;
    for(int i = 1;i <= 30000;i++) {
        if(i % 6 == 0) {
            six.push_back(i);
        }
        else if(i % 2 == 0) {
            two.push_back(i);
        }
        else if(i % 3 == 0) {
            three.push_back(i);
        }
    }
    if(N == 3) {
        cout << "2 5 63" << endl;
    }
    else if(N == 4) {
        cout << "2 5 20 63" << endl;
    }
    else {
        int A = 0;
        int B = 0;
        int C = 0;
        for(int i = 1;i <= 10000;i++) {
            bool cnt = true;
            for(int j = 1;j <= 5000;j++) {
                if(i % 2 == 0 && j % 2 == 0) {
                    if(N >= i + j && N - (i + j) <= 5000) {
                        A = i;
                        B = j;
                        C = N - A - B;
                        cnt = false;
                        break;
                    }
                }
            }
            if(cnt == false) {
                break;
            }
        }
        for(int i = 0;i < A;i++) {
            cout << two.at(i) << " ";
        }
        for(int i = 0;i < B;i++) {
            cout << three.at(i) << " ";
        }
        for(int i = 0;i < C;i++) {
            cout << six.at(i) << " ";
        }
        cout << endl;
    }
}