#include <iostream>
#include <cstdio>
using namespace std;

int main(){
    string s, t;
    cin >> s >> t;

    string rotate = s;
    for(long long i = 0; i < s.size(); i++){
        rotate = rotate[rotate.size()-1] + rotate.substr(0, rotate.size()-1);
        if(rotate == t){
            printf("Yes\n");
            return 0;
        }
    }
    printf("No\n");
    return 0;
}