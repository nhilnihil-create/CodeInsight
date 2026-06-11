#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int A, B, C;
    cin >> A >> B >> C;
    int ans;
    if((A + B + C) % 2 == 0){
        if(A % 2 == 0 && B % 2 == 0 && C % 2 == 0){
            vector<int> vec{A, B, C};
            sort(vec.begin(), vec.end());
            ans = (vec.at(2) - vec.at(0)) / 2 + (vec.at(2) - vec.at(1)) / 2;
        }else{
        if(A % 2 == 1) A++;
        if(B % 2 == 1) B++;
        if(C % 2 == 1) C++;
        vector<int> vec{A, B, C};
        sort(vec.begin(), vec.end());
        ans = (vec.at(2) - vec.at(0)) / 2 + (vec.at(2) - vec.at(1)) / 2 + 1;
        }
    }
    else{
        if(A % 2 == 1 && B % 2 == 1 && C % 2 == 1){
            vector<int> vec{A, B, C};
            sort(vec.begin(), vec.end());
            ans = (vec.at(2) - vec.at(0)) / 2 + (vec.at(2) - vec.at(1)) / 2;
        }else{
        if(A % 2 == 0) A++;
        if(B % 2 == 0) B++;
        if(C % 2 == 0) C++;
        vector<int> vec{A, B, C};
        sort(vec.begin(), vec.end());
        ans = (vec.at(2) - vec.at(0)) / 2 + (vec.at(2) - vec.at(1)) / 2 + 1;
        }
    }
    cout << ans << endl;
}