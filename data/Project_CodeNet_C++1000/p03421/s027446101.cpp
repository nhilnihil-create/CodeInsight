#include <iostream>
#include <array>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <string>
using namespace std;

int main(){
    int N, A, B;
    cin >> N >> A >> B;

    if(A + B - 1 > N){
        cout << -1 << endl;
        return 0;
    }

    vector<int> ans;
    int rest = N - A;
    int now = 0;
    for(int i = 0; i < A; ++i){
        if(rest > 0){
            int temp = min(rest + 1, B);
            for(int j = 0; j < temp; ++j){
                ans.push_back(now + temp - j);
            }
            now += temp;
            rest -= temp - 1;
        } else {
            ans.push_back(now + 1);
            now++;
        }
    } 
    if(ans.size() != N){
        cout << "-1" << endl;
        return 0;
    }
    for(int i = 0; i < N; ++i){
        cout << ans[i];
        if(i != N - 1) cout << " ";
    }
    cout << endl;
}
