#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
    int N , x;
    cin >> N >> x;
    vector <int> a(N);
    for(int i = 0; i < N; i++){
        cin >> a[i];
    }
    sort(a.begin() , a.end());
    int t = 0;
    for(int i = 0; i < N; i++){
        x-=a[i];
        if(x >= 0){
            t++;
        }
        else{
            break;
        }
    }
    if(t == N && x > 0){
        t--;
    }
    cout << t << endl;
}