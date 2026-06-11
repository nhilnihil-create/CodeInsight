#include<iostream>
#include<deque>
using namespace std;

long long N, A, B;

int main(){
    cin >> N >> A >> B;

    if(A + B > N + 1 || A * B < N){
        cout << -1 << endl;
        return 0;
    }

    deque<long long> res;
    int cnt = 0;
    long long resid = N - (A + B - 1);
    for(int b = 0; b < B - 1; b++){
        int tmp = 1 + min(A - 1, resid);
        for(int a = 0; a < tmp; a++){
            res.push_front(cnt + tmp - a);
        }
        cnt += tmp;
        resid -= tmp - 1;
    }
    for(int a = 0; a < A; a++){
        res.push_front(cnt + A - a);
    }
    for(auto itr = res.begin(); itr != res.end(); ++itr){
        cout << *itr << " ";
    }

    cout << endl;
}
