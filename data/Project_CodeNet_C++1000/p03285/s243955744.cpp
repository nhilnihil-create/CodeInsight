#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin >> N;

    bool ans = false;
    int d = 0;
    int c = 0;
    while(4*d <= N){
        while(4*d+7*c <= N){
            if(4*d+7*c == N){
                ans = true;
                break;
            }
            c++;
        }
        if(ans) break;
        c=0;
        d++;
    }
    string answer = "";
    if(ans){
        answer = "Yes";
    } else{
        answer = "No";
    }
    
    cout << answer << endl;
}