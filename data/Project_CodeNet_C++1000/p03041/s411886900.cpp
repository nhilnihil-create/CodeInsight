#include <bits/stdc++.h>
using namespace std;

int N,K;
string S;
char a;

int main() {
    cin>>N>>K>>S;
    S[K-1] = S[K-1] - 'A'+'a';
    cout <<S;
}