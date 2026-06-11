#include<iostream>
#include<algorithm>
#include<string>
#include<cmath>
#include<vector>
#include<map>
using namespace std;
int main() {
    int N;
    cin >> N;
    int t[100001], x[100001], y[100001];
    for(int i = 1; i <= N; i++) cin >> t[i] >> x[i] >> y[i];
    t[0] = 0;
    x[0] = 0;
    y[0] = 0;
    bool plan = true;
    for(int i = 1; i <= N; i++){
        if((t[i]-t[i-1])%2 == 1){
            int move = abs(x[i]-x[i-1])+abs(y[i]-y[i-1]);
            if(move > (t[i]-t[i-1]) || move%2 == 0){
                plan = false;
            }
        }

        else {
            int move = abs(x[i]-x[i-1])+abs(y[i]-y[i-1]);
            if(move > (t[i]-t[i-1]) || move%2 == 1){
                plan = false;
            }
        }
    }
    if(plan) {
        cout << "Yes" << endl;
        return 0;
    }
    cout << "No" << endl;
    return 0;
}