#include <iostream>
#include <string>

using namespace std;
typedef long long ll;

int main(){
    string s;
    cin >> s;
    const ll half = (s.size() + 1) / 2;
    if(s.size() % 2 == 1){
        ll i = 0;
        for(; i <= s.size() / 2; ++i){
            if(s.at(half - 1 + i) != s.at(half - 1) ||
               s.at(half - 1 - i) != s.at(half - 1)){
                break;
            }
        }
        cout << half + i - 1 << endl;
    }else{
        ll i = 1;
        for(; i <= s.size() / 2; ++i){
            if(s.at(half - 1 + i) != s.at(half - 1) ||
               s.at(half - 1 - (i - 1)) != s.at(half - 1)){
                break;
            }
        }
        cout << half + i - 1 << endl;
    }
    return 0;
}
