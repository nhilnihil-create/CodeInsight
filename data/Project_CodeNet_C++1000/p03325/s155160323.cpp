#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int N;
    cin >> N;
    vector<ll> a(N);
    for(int i=0;i<N;i++) {
        cin >> a.at(i);
    }
    int cnt = 0;
    int buf = 0;
    for(int i=0;i<N;i++) {
        if(a.at(i)%2==0) {
            for(int j=1;j<31;j++) {
                if(a.at(i)%2!=0) {
                    break;
                }else{
                    a.at(i) = a.at(i) / 2;
                    buf++;
                }
            }
        }
        cnt = max(cnt,buf);
    }
    cout << cnt << endl;
}