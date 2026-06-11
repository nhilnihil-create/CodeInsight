#include <bits/stdc++.h>
#define rep(i, z, n) for(int i = z; i < n; i++)
#define all(v) v.begin(), v.end()
typedef long long ll;
//const int INF = 1<<29;
using namespace std;

int main(){
    int N;
    cin >> N;
    stack<int> s;
    int64_t cnt = 1;
    if (N == 0){
        cout << 0;
    }
    while(N != 0){
        if (N == cnt){
            s.push(1);
            N -= cnt;
            break;
        }
        if (N % (cnt * 2) != 0){
            //cout << "cnt " << cnt << endl;
            s.push(1);
            N -= cnt;
        }
        else{
            s.push(0);
        }
        cnt *= -2;
        //cout << N << endl;
    }
    //cout << "OK" << endl;
    while(!s.empty()){
        int x = s.top();
        s.pop();
        cout << x;
    }
    cout << endl;
}
