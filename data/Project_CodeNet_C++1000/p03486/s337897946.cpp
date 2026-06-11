#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
    string s, t;
    cin >> s >> t;

    sort(s.begin(), s.end());
    sort(t.begin(), t.end(), greater<char>());

    //cout << "s " << s << endl;
    //cout << "t " << t << endl;

    if(s < t){
        printf("Yes\n");
    }
    else{
        printf("No\n");
    }

    return 0;
}