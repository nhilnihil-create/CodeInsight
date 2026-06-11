#include <bits/stdc++.h>
using namespace std;
int main(void){
    int N;
    cin >> N;
    vector<int> input(N);
    for(auto& inp: input){
        cin >> inp;
    }
    input.push_back(0);
    sort(input.begin(), input.end(), greater<int>());
    deque<int> dque;
    int cnt = 0;
    while(input.size()){
        if(cnt++ % 2 == 0){
            dque.push_back(input.back());
            input.pop_back();
        }else{
            dque.push_front(-(input.back()));
            input.pop_back();
        }
    }
    vector<int> res(N + 1);
    for(int i = 0; i < N; i++){
        res[i] = min(dque[i + 1] - dque[i], 24 - (dque[i + 1] - dque[i]));
    }
    res[N] = min(dque[N] - dque[0], 24 - (dque[N] - dque[0]));
    cout << *min_element(res.begin(), res.end()) << endl; 
}