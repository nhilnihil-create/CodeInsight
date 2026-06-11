/*
数学的にすべての場合を計算で求めようとして失敗した（うまく考えられなかった）
よくよく考えると組み合わせは１０通りしかないから、すべての組み合わせを試すと良かった.
*/

#include <bits/stdc++.h>
using namespace std;

string s;
int n;
long long m, a, r, c, h;
long long D[5];
vector<int> p = {0,0,0,0,0,0,1,1,1,2};
vector<int> q = {1,1,1,2,2,3,2,2,3,3};
vector<int> R = {2,3,4,3,4,4,3,4,4,4};

int main(){
    cin >> n;
    
    for (int i = 0; i < n; i++){
        cin >> s;
        
        if (s[0] == 'M') m++;
        else if (s[0] == 'A') a++;
        else if (s[0] == 'R') r++;
        else if (s[0] == 'C') c++;
        else if (s[0] == 'H') h++;
    }
    
    D[0] = m, D[1] = a, D[2] = r, D[3] = c, D[4] = h;
    long long res = 0;
    for (int d = 0; d < 10; d++) res += D[p[d]] * D[q[d]] * D[R[d]];
    
    cout << res << endl;
}