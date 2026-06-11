#include <iostream>
#include <set>
#include <string>

using namespace std;

const long MOD = 1000000007;
typedef pair<int, int> P;
typedef long long ll;

int main(){
    string s;
    cin >> s;
    int K;
    cin >> K;

    set<string> stset;
    for(int i=0; i<s.length(); i++){
        for(int l=1; l<=5; l++){
            if(i+l > s.length()) continue;
            string t = s.substr(i, l);
            stset.insert(t);
        }
    }

    int cnt = 1;
    for(auto st : stset){
        if(cnt == K){
            cout << st << endl;
            break;
        }
        cnt++;
    }


    return 0;
}
