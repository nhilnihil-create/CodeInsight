#include <iostream>
#include <algorithm>
#include <string>
#include <set>

using namespace std;

int main(){
    int K;
    string s;
    cin >> s;
    cin >> K;
    int N = s.length();
    set<string> ss;
    for(int i=1; i<=K; i++){
        for(int j=0; j<N-i+1; j++){
            ss.insert(s.substr(j, i));
        }
    }
    auto itr = ss.begin();
    for(int i=0; i<K-1; i++){
        ++itr;
    }
    cout << * itr << endl;
    return 0;
}