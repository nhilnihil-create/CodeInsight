#include <iostream>
using namespace std;

int main(){
    string s;cin>>s;
    int remains = 15 - s.size();
    int need_to_win = 8 - remains;
    int acc = 0;
    for (auto c: s){
        if (c == 'o'){
            acc++;
        }
    }
    if (acc >= need_to_win){
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}
