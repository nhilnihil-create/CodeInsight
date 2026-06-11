#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main(){

    int n, k;
    string s;
    cin >> n >> k >> s;

    transform(s.begin() + k - 1, s.begin() + k, s.begin() + k - 1, ::tolower);

    // if(s[k - 1] == 'A' ){
    //     s[k - 1] = 'a';
    // }else if(s[k - 1] == 'B'){
    //     s[k-1] = 'b';
    // }else{
    //     s[k-1] = 'c';
    // }

    cout << s;

    return 0;
}