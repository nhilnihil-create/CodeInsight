#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int n; cin >> n;
    vector<int> x;
    vector<int> memo;
    for(int i=0; i<n; i++){
        int tmp=0;
        cin >> tmp;
        x.push_back(tmp);
        memo.push_back(tmp);
    }
    int left = 0, right = 0;
    sort(x.begin(), x.end());
    left = x[n/2-1];
    right = x[n/2];
    for(int i=0; i<n; i++){
        if(memo[i]<= left)
            cout << right << endl;
        else if(memo[i]>=right)
            cout << left << endl;
    }
    return 0;

}