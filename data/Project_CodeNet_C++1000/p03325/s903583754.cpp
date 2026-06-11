#include<bits/stdc++.h>
using namespace std;

int N=10000;
vector <long long> a(N,0);

void ans() {
    long long cnt = 0;
    for (int i=0; i<N; i++) {
        while(a.at(i)%2==0) {
            a.at(i)/=2;
            cnt++;
        }
    }
    cout << cnt;
}

int main() {
    cin >> N;
    for (int i=0; i<N; i++) cin >> a.at(i);
    ans();
}