#include <iostream>
#include <cstdio>
using namespace std;

int main(){
    string s;
    cin >> s;

    long long minv = 1e9;
    for(long long i = 0; i + 2< s.size(); i++){
        string t= s.substr(i, 3);
        //printf("t %s\n", t.c_str());
        long long a = stoll(t);
        minv = min(minv, abs(a-753));
    }
    cout << minv << endl;
    return 0;
}