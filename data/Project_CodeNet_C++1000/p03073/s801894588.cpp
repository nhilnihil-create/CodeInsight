#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main(){
    string S;
    cin >> S;
    int N = S.size();
    vector<char> s1(N), s2(N);
    for(int i = 0; i < N; i++){
        if(i % 2 == 0) {
            s1[i] = '1';
            s2[i] = '0';
        }
        else{
            s1[i] = '0';
            s2[i] = '1';
        }
    }
    int cnt1 = 0, cnt2 = 0;
    for(int i = 0; i < N; i++){
        if(S[i] != s1[i]) cnt1++;
        if(S[i] != s2[i]) cnt2++;
    }
    cout << min(cnt1, cnt2) << endl;
}