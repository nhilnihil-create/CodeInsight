#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
using namespace std;
const int MAX_N=50;
int N,K;
string S;
int main(){
    cin >> N >> K;
    cin >> S;
    S[K-1]=tolower(S[K-1]);
    printf("%s\n",S.c_str());
}