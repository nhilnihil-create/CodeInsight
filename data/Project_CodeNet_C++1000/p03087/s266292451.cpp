#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int main(){
    int N, Q;
    cin >> N >> Q;
    string S;
    cin >> S;
    int flag = 0;
    vector<int> ind;
    for(int i = 0; i < N; i++){
        if(S[i] == 'A') {
            flag = 1;
        }
        else if(flag == 1 && S[i] == 'C'){
            flag = 0;
            ind.push_back(i);
        }
        else{
            flag = 0;
        }
    }
    for(int i = 0; i < Q; i++){
        int l, r;
        cin >> l >> r;
        l--;
        r--;
        int t = upper_bound(ind.begin(), ind.end(), r) - upper_bound(ind.begin(), ind.end(), l);
        cout << t << endl;
    }
}