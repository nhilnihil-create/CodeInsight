#include <iostream>
#include <vector>
#include <map>
#include <utility>
#include <algorithm>
using namespace std;
typedef pair<int, int> P;
int main(){
    int N;
    cin >> N;
    vector<int> A(N);
    for(int i = 0; i < N; i++) cin >> A[i];
    map<int, int> m1, m2;
    for(int i = 0; i < N; i += 2){
        m1[A[i]]++;
    }
    for(int i = 1; i < N; i += 2){
        m2[A[i]]++;
    }
    vector<P> num1, num2;
    for(auto v: m1){
        num1.push_back(P(v.second, v.first));
    }
    for(auto v: m2){
        num2.push_back(P(v.second, v.first));
    }
    sort(num1.begin(), num1.end());
    sort(num2.begin(), num2.end());
    int ans = 1e9;
    if(num1.size() == 1 && num2.size() == 1 && num1[0].second == num2[0].second){
        cout << N / 2 << endl;
        return 0;
    }
    for(int i = (int)num1.size() - 1; i >= 0 && i >= (int) num1.size() - 2; i--){
        for(int j = (int)num2.size() - 1; j >= 0 && j >= (int)num2.size() - 2; j--){
            if(num1[i].second != num2[j].second){
                ans = min(ans, N - num1[i].first - num2[j].first);
            }
        }
    }
    cout << ans << endl;
}