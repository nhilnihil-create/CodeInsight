#include <iostream>
#include <string> 
using namespace std;
int main(){long long K,an=0;string S;cin >> S >> K;while (an<K-1&&S.at(an) == '1'){an++;}cout << S.at(an) << endl;}