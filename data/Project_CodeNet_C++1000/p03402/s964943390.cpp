#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int A, B; cin >> A >> B;
    vector<vector<char>> m(100, vector<char>(100));

    for (int i = 0; i < 50; i++)
    {
        for (int j = 0; j < 100; j++)
        {
            if(j%2==0 && i%2==0 && B>1){
                m[i][j] = '#';
                B--;
            } else {
                m[i][j] = '.';
            }
        }
    }
    for (int i = 50; i < 100; i++)
    {
        for (int j = 0; j < 100; j++)
        {
            if(j%2==0 && i%2==1 && A>1){
                m[i][j] = '.';
                A--;
            } else {
                m[i][j] = '#';
            }
        }
    }
    cout << 100 << " " << 100 << endl;
    for(auto i : m){
        for(char c : i){
            cout << c;            
        }
        cout << endl;
    }
}