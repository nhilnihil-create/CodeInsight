#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <stack>
#include <set>
#include <map>
using namespace std;
typedef long long ll;

int main(){
    string s;
    cin >> s;
    int N = s.size();

    bool canMake = true;
    if(s[0] != '1') canMake = false;
    if(s[N - 1] != '0') canMake = false;
    for(int i = 0; i < N - 1; i++){
        if(s[i] != s[N - 2 - i]) canMake = false;
    }

    if(!canMake){
        cout << -1 << endl;
        return 0;
    }

    //canMake
    int node = 1; //見ている点
    for(int i = 0; i < N - 1; i++){
        if(s[i] == '1'){
            cout << node << " " << i + 2 << endl;
            node = i + 2;
        }
        else {
            cout << node << " " << i + 2 << endl;
        }
    }

    return 0;
}