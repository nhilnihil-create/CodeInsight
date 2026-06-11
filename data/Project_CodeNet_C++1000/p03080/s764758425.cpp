#include <bits/stdc++.h>
using namespace std;

int main(){
    int A, B, C, N, M ,K;
    int sum = 0;
    int t = 0;
    string s, s1;
    cin >> N >> s;

    for(int i = 0; i < N; i++){
        if(s.at(i) == 'R') t++;
        else t--;
    }

    if(t > 0) cout << "Yes" << endl;
    else cout << "No" << endl;
//    vector<int> X();

//    for(int i = 0; i < ; i++){}
//    for(int j = 0; j < ; j++){}

//    cout <<  << endl;
}